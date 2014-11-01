/**
 * File Contents:
 * Hash Definitions
 *
 *  Created on: Oct 12, 2014
 *      Author: Brandon Zhen
 */

#ifndef HASH_HPP_
#define HASH_HPP_

typedef unsigned long		hash_t;
typedef unsigned long long	lhash_t;

#define hash_t_max	6
#define lhash_t_max	12

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
void hash(hash_t& hash, char append, char len = hash_t_max);

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
void lhash(lhash_t& hash, char append, char len = lhash_t_max);

#endif /* HASH_HPP_ */
