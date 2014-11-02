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
#include <vector>
#include <fstream>
#include <cstdlib>
#include "hash.hpp"

typedef signed long rank_t;

/**
 * @param	keyword	An array of POINTERS to ARRAYS of keyword strings
 * @param	rank	An array of POINTERS to ARRAYS of keyword worth
 * @param	hash	An array of POINTERS to ARRAYS of keyword hashes
 * @param	maxlen	The maximum character <length> of the <hash>es
 * @note	indexes shall be defined by the 1st character of the hash
 */
struct keys {
	std::vector<std::string> keyword[32];
	std::vector<rank_t> rank[32];
	std::vector<hash_t> hash[32];
	unsigned maxlen = hash_t_len_max;
};

/**
 * Keys Loader
 * @file	format		<rank>|<keyword>
 * @file	<rank>		A '+' or '-' number
 * @file	<keyword>	Either a word or a phrase, lower-case, > 3 characters
 * @file	example		-5|dear
 * @file	example		+69|penis enlargements
 *
 * @param	keyset		The <Keys> object to fill
 * @param	filename	The filename of the input data
 * @return	true on load successful
 * @return	false on load failure
 */
bool load(keys& keyset, char const* filename);

/**
 * Binary Hash Table Search
 * @param	str		The input string
 * @param	begin	The first string index hashed
 * @param	input	The input string's <hash> to compare
 * @param	keyset	The set of pre-sorted keywords to compare <hash> to
 * @return	The rank associated with the longest keyword matched
 * @return	0 when no match is found
 */
signed rankThis(std::string& str, unsigned begin, hash_t input, keys& keyset);

/**
 * @param	keyword	An array of POINTERS to ARRAYS of keyword strings
 * @param	rank	An array of POINTERS to ARRAYS of keyword worth
 * @param	hash	An array of POINTERS to ARRAYS of keyword long hashes
 * @param	maxlen	The maximum character <length> of the <hash>es
 */
struct lkeys {
	std::vector<std::string> keyword[32];
	std::vector<rank_t> rank[32];
	std::vector<lhash_t> hash[32];
	unsigned maxlen = lhash_t_len_max;
};

#endif /* KEYS_HPP_ */
