/**
 * File Contents:
 * Hash Definitions
 *
 *  Created on: Oct 12, 2014
 *      Author: Brandon Zhen
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#include <string>

typedef unsigned p_hash_t;

/**
 * @param	text	The string to hash completely
 * @return	An 8 bit wide hash between 0 - 127
 */
signed char hash(std::string text) {
	return 0;
}

/**
 * @param	text	The substring to hash
 * @param	begin	The first index of the substring
 * @param	end		The last index of the substring
 * @return	An 8 bit wide hash between 0 - 127
 */
signed char hash(std::string text, unsigned begin, unsigned end) {
	return 0;
}

/**
 * @param	hash		The <hash> to update
 * @param	append_char	The character to hash into <hash>
 * @param	dehash_char	The character to hash out of <hash>
 * @return	An 8 bit wide hash between 0 - 127
 */
signed char update_hash(signed char hash, char append_char, char dehash_char) {
	return 0;
}

/**
 * This function creates a perfect alphabet hash such that:
 * Example: p_hash("ab") != p_hash("ba")
 * Example: p_hash("Ab") == p_hash("aB")
 * Usage: [ update_p_hash(empty_hash, new_character, 6); ]
 *
 * @param	hash	The <hash> to append <characters> to
 * @param	append	The single <character> from aA~zZ to append to <hash>
 * @param	len		The max character <length> the <hash> contains [max == 6]
 * @return	A 30 bit wide hash containing the hash of <length> characters
 */
void p_hash(p_hash_t& hash, char append, char len = 6) {
	hash = ((hash << 5) | (append & 0b11111)) & 07777777777;
}

#endif /* HASH_HPP_ */
