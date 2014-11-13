/*
 * keys.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: Brandon Zhen
 */

#include "keys.hpp"

/**
 * Keys Loader
 * @file	format		<rank>|<keyword>\n
 * @file	<rank>		A '+' or '-' number
 * @file	<keyword>	Either a word or a phrase, lower-case, > 3 characters
 * @file	example		-5|dear
 * @file	example		+69|penis enlargements
 * @file	note		Some systems append \r before \n
 *
 * @param	keyset		The <Keys> object to fill
 * @param	filename	The filename of the input data
 * @return	true on load successful
 * @return	false on load failure
 */
bool load(keys& keyset, char const* filename) {
	std::ifstream in(filename);
	if (in.fail())
		return false;
	while (!in.eof()) {
		std::string str;
		getline(in, str);
		unsigned delimination_index = str.find('|');
		unsigned hash_index = str[delimination_index + 1] & 0b11111;
		unsigned word_length = str.length() - delimination_index - 1;
		keyset.keyword[hash_index].push_back(str.substr(
				delimination_index + 1, word_length));
		keyset.rank[hash_index].push_back(std::atoi(
				str.substr(0, delimination_index).c_str()));
		if (word_length < keyset.maxlen)
			keyset.maxlen = word_length;
	}
	for (unsigned i = 0; i < 32; i++) {
		/* Bubbly Sort */
		if (keyset.keyword[i].size() > 1)
			for (unsigned top = 0,
					bot = keyset.keyword[i].size() - 1,
					next_top = keyset.keyword[i].size() - 1;
					top < keyset.keyword[i].size() - 1;
					top = next_top,
					next_top = bot = keyset.keyword[i].size() - 1)
				for (; top < bot; bot--)
					if (keyset.keyword[i][bot - 1].compare(
							keyset.keyword[i][bot]) > 0)
						std::swap(
								keyset.keyword[i][bot],
								keyset.keyword[i][bot - 1]),
						std::swap(
								keyset.rank[i][bot],
								keyset.rank[i][bot - 1]),
						next_top = bot;
		keyset.hash[i].resize(keyset.keyword[i].size());
		for (unsigned v = 0; v < keyset.keyword[i].size(); v++)
			for (unsigned s = 0; s < keyset.maxlen; s++)
				hash(keyset.hash[i][v], keyset.keyword[i][v][s], keyset.maxlen);
	}
	return true;
}

/**
 * Binary Hash Table Search
 * @param	str		The input string
 * @param	begin	The first string index hashed
 * @param	input	The input string's <hash> to compare
 * @param	keyset	The set of pre-sorted keywords to compare <hash> to
 * @return	The rank associated with the longest keyword matched
 * @return	0 when no match is found
 */
signed rankThis(std::string& str, unsigned begin, hash_t input, keys& keyset) {
	unsigned const hash_index = input >> (keyset.maxlen - 1) * 5;

	/* Size Check */
	if (keyset.hash[hash_index].size() == 0)
		return 0;

	unsigned high = keyset.hash[hash_index].size() - 1;
	unsigned low = 0;
	signed rank = 0;
	unsigned vec_i;

	/* Boundary check because for loop does not check boundaries */
	if (keyset.hash[hash_index][vec_i = low] == input
			|| keyset.hash[hash_index][vec_i = high] == input)
		goto matched;

	for (vec_i = high >> 1; high - low > 1; vec_i = (high + low) >> 1) {
		if      (keyset.hash[hash_index][vec_i] > input)
			high = vec_i;
		else if (keyset.hash[hash_index][vec_i] < input)
			low = vec_i;
		else /* (keyset.hash[hash_index][vec_i] == input) */ {
			/* Hash matched */

			matched:
			unsigned comparelen =	//length to compare
				keyset.keyword[hash_index][vec_i].length()
				- keyset.maxlen;
			signed sig =			//(keyword_string).compare(input_string)
				keyset.keyword[hash_index][vec_i].substr(
				keyset.maxlen, comparelen).compare(str.substr(
				begin + keyset.maxlen, comparelen));

			if (sig < 0)			//1.compare(2) < 0
				high = vec_i;
			else if (sig > 0)		//2.compare(1) > 1
				low = vec_i;
			else /* (sig == 0) */ {	//3.compare(3) == 0
				/* Keyword completely matches */
				rank = keyset.rank[hash_index][vec_i];			//Rank Updated

				/* Check for longer keywords */
				while (++vec_i < high
						&& keyset.hash[hash_index][vec_i] == input) {
					unsigned comparelen =	//length to compare
						keyset.keyword[hash_index][vec_i].length()
						- keyset.maxlen;
					if ( /* (keyword_string).compare(input_string) == 0 */
							keyset.keyword[hash_index][vec_i].substr(
							keyset.maxlen, comparelen).compare(str.substr(
							begin + keyset.maxlen, comparelen)) == 0)
						rank = keyset.rank[hash_index][vec_i];	//Rank Updated
					else /* match failure */
						return rank;		//return pre(++vec_i)_rank;
				}
				/* ++vec_i previously already failed */
				return rank;				//return pre(++vec_i)_rank;
			}
		}
	}
	return 0;								//return no_matches_found;
}
