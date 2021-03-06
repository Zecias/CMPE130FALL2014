/**
 * File Contents:
 * Rabin�Karp Algorithm Declarations
 *
 *  Created on: Oct 9, 2014
 *      Author: Brandon Zhen
 */

#ifndef KARP_HPP_
#define KARP_HPP_

#include "keys.hpp"
#include "hash.hpp"

/**
 * @param	input_string	The string you want to search through
 * @param	search_keys		The container of keyword you want to search for
 * @return	A score from ~[-100] to ~[+100] based on the <Keys> database
 */
rank_t rankString(std::string input_string, keys search_keys);

#endif /* KARP_HPP_ */
