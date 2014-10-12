/**
 * File Contents:
 * Rabin–Karp Algorithm Definitions
 *
 *  Created on: Oct 12, 2014
 *      Author: Brandon Zhen
 */

/**
 * @param	input_string	The string you want to search through
 * @param	search_keys		The container of keyword you want to search for
 * @return	A score from 0 - 100 determining how much was matched
 */
unsigned rankString(std::string input_string, keys search_keys) {/*
	assume_all_keys_hashed_in_main
	DECLARE_HASH_OF_input_string_BASED_ON_(minimum_length_of?)_KEYS
		^make_that_O(1)_complexity
	DECLARE_RANK=0
	for_all_input_string_segments
		MATCH_HASH_WITH_SET_OF_KEYS
		if_probable_match
			CHECK_FOR_PERFECT_MATCH_WITH_KEY[]
			if_perfect_match
				RANK+=KEY'S_RANK
		REHASH(CURRENT_HASH - PREVIOUS_HASH + NEXT_HASH)
	return RANK
*/}
