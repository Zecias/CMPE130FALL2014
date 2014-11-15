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
	unsigned vec_i;

	/* Boundary check because for loop does not check boundaries */
	if (keyset.hash[hash_index][vec_i = low] == input)
		goto matchedL;
	if (keyset.hash[hash_index][vec_i = high] == input)
		goto matchedH;

	/* Content binary search for first hash match */
	for (vec_i = high >> 1; high - low > 1; vec_i = (high + low) >> 1) {
		if      (keyset.hash[hash_index][vec_i] > input)
			high = vec_i;
		else if (keyset.hash[hash_index][vec_i] < input)
			low = vec_i;
		else /* (keyset.hash[hash_index][vec_i] == input) */ {
			/* Hash matched */

			matchedL:
			/* Find last matchable hash */
			while (keyset.hash[hash_index][++vec_i] == input);
			vec_i--;

			matchedH:
			while (keyset.hash[hash_index][vec_i] == input) {
				if (keyset.keyword[hash_index][vec_i].compare(
						keyset.maxlen,
						keyset.keyword[hash_index][vec_i].length()
							- keyset.maxlen,
					str,
						begin + keyset.maxlen,
						keyset.keyword[hash_index][vec_i].length()
							- keyset.maxlen)
					== 0)
						return keyset.rank[hash_index][vec_i];
				if (vec_i == 0)
					return 0;		//return on hash match but no keyword match
				else /* vec_i_last > 0 */
					vec_i--;
			}
			return 0;				//return on hash match but no keyword match
		}
	}
	return 0;						//return when no hash match;
}
