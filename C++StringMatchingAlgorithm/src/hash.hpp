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

#endif /* HASH_HPP_ */
