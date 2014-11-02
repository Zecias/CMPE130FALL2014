/**
 * File Contents:
 * Rabin–Karp Algorithm Definitions
 *
 *  Created on: Oct 12, 2014
 *      Author: Brandon Zhen
 */

#include "karp.hpp"

/**
 * @param	input_string	The string you want to search through
 * @param	search_keys		The container of pre-sorted keywords to search for
 * @return	A score from ~[-100] to ~[+100] based on the <Keys> database
 */
rank_t rankString(std::string input_string, keys search_keys) {
	rank_t rank = 0;
	hash_t strhash = 0x0;
	unsigned i = 0;
	while (i < search_keys.maxlen - 1 && i < input_string.length()) {
		hash(strhash, input_string[i++], search_keys.maxlen);
	}
	for (; i < input_string.length(); i++) {
		hash(strhash, input_string[i], search_keys.maxlen);
		rank += rankThis(input_string, i, strhash, search_keys);
	}
	return rank;
}
