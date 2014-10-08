/**
 * File Contents:
 * A container class for a vector of keyword strings and their hashes
 *
 *  Created on: Oct 9, 2014
 *      Author: Brandon Zhen
 */

#ifndef KEYS_HPP_
#define KEYS_HPP_

#include <iostream>
#include <vector>

/**
 * @file	Input file formatting and details
 */
class keys {
	std::vector<std::string> keywords;
	std::vector<signed char> hashes;
public:
	keys();								//Default Constructor
	keys(std::ifstream& filename);		//Autopilot Constructor

	bool load(std::ifstream& filename);
	void rehash();	//etc etc..
};

#endif /* KEYS_HPP_ */
