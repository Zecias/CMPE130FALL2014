/**
 * File Contents:
 * A container class for a vector of keyword strings and their rank and hashes
 *
 *  Created on: Oct 9, 2014
 *      Author: Brandon Zhen
 */

#ifndef KEYS_HPP_
#define KEYS_HPP_

#include <vector>

/**
 * @param	keyword	A vector of the keyword strings
 * @param	rank	A vector of the worth of each keyword
 * @param	hashe	A vector of the hashes of each keyword
 */
struct keys {
	std::vector<std::string> keyword;
	std::vector<signed char> rank;
	std::vector<signed char> hash;
};

#endif /* KEYS_HPP_ */
