/*
 * hash.cpp
 *
 *  Created on: Oct 31, 2014
 *      Author: Brandon Zhen
 */

#include "hash.hpp"

/**
 * This function creates a perfect alphabet hash such that:
 * Example: hash("ab") != hash("ba")
 * Example: hash("Ab") == hash("aB")
 * Usage: [ hash(empty_hash, 'a', 3); ]
 *
 * @param	hash	The <hash> to append <characters> to
 * @param	append	The single <character> from aA~zZ to append to <hash>
 * @param	len		The max character <length> the <hash> contains [max == 6]
 * @return	A 30 bit wide hash containing the hash of <length> characters
 */
void hash(hash_t& hash, char append, signed len) {
	hash = ((hash << 5) | (append & 0b11111))
		& (hash_t_mask_max >> (hash_t_len_max - len) * 5);
}

/**
 * This function creates a perfect alphabet hash such that:
 * Example: lhash("ab") != lhash("ba")
 * Example: lhash("Ab") == lhash("aB")
 * Usage: [ lhash(empty_hash, 'a', 9); ]
 *
 * @param	hash	The <hash> to append <characters> to
 * @param	append	The single <character> from aA~zZ to append to <hash>
 * @param	len		The max character <length> the <hash> contains [max == 12]
 * @return	A 60 bit wide hash containing the hash of <length> characters
 */
void lhash(lhash_t& hash, char append, signed len) {
	hash = ((hash << 5) | (append & 0b11111))
		& (lhash_t_mask_max >> (lhash_t_len_max - len) * 5);
}
