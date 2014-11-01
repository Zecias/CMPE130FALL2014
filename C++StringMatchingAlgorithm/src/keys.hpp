/**
 * File Contents:
 * A container class for a vector of keyword strings and their rank and hashes
 *
 *  Created on: Oct 9, 2014
 *      Author: Brandon Zhen
 */

#ifndef KEYS_HPP_
#define KEYS_HPP_

#include <string>
#include "hash.hpp"

typedef signed long rank_t;

/**
 * @param	keyword	An array of pointers to 'sets' of keyword strings
 * @param	rank	An array of pointers to 'sets' of keyword worth
 * @param	hash	An array of pointers to 'sets' of keyword hashes
 * @param	hlen	The character <length> the <hash>es contain
 */
struct keys {
	std::string *keyword[32];
	rank_t *rank[32];
	hash_t *hash[32];
	signed hlen = hash_t_max;
};

/**
 * @param	keyword	An array of pointers to 'sets' of keyword strings
 * @param	rank	An array of pointers to 'sets' of keyword worth
 * @param	hash	An array of pointers to 'sets' of keyword long hashes
 * @param	hlen	The character <length> the <hash>es contain
 */
struct lkeys {
	std::string *keyword[32];
	rank_t *rank[32];
	lhash_t *hash[32];
	signed hlen = lhash_t_max;
};

#endif /* KEYS_HPP_ */
