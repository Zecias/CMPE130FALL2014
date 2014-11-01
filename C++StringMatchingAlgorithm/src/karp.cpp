/**
 * File Contents:
 * Rabin–Karp Algorithm Definitions
 *
 *  Created on: Oct 12, 2014
 *      Author: Brandon Zhen
 */

#include "karp.hpp"

/**
 * @param	input_string	The string you want to search through
 * @param	search_keys		The container of keyword you want to search for
 * @return	A score from 0 - 100 determining how much was matched
 */
unsigned rankString(std::string input_string, keys search_keys) {
//	assume_all_keys_hashed_in_main
	hash_t strhash = 0;
//	DECLARE_HASH_OF_input_string_BASED_ON_(minimum_length_of?)_KEYS
//		^make_that_O(1)_complexity
//	DECLARE_RANK=0
//	for_all_input_string_segments
//		MATCH_HASH_WITH_SET_OF_KEYS
//		if_probable_match
//			CHECK_FOR_PERFECT_MATCH_WITH_KEY[]
//			if_perfect_match
//				RANK+=KEY'S_RANK
//		REHASH(CURRENT_HASH - PREVIOUS_HASH + NEXT_HASH)
//	return RANK

	return 0;
}


//#define hashlimit 3
//
//void main_1() {
//	vector<string> keywords;			//Declarations
//	vector<signed> hashes;
//
//	ifstream file("key.txt");			//Get Keywords
//	while (!file.eof()) {
//		string str;
//		getline(file, str);
//		keywords.push_back(str);
//	}
//
//	for (auto spamgods : keywords) {	//Hash Keywords
//		signed hash = 0;
//		for (int i = 0; i < hashlimit; i++)
//			hash += spamgods[i];
//		hashes.push_back(hash);			//Shows Body Text
//	}
//
//	file.close();//Mush
//	file.open("doc.txt");				//Get Body Text
//	string bodytext;
//	getline(file, bodytext);
//	cout << bodytext << endl;
//
//	signed dochash = 0;					//Initial Hash of Body Text
//	for (int i = 0; i < hashlimit; i++)
//		dochash += bodytext[i];
//
//	for (unsigned i = hashlimit; i < bodytext.length(); i++) {
//		for (unsigned j = 0; j < hashes.size(); j++) {
//			if (dochash == hashes[j]) {	//Possible Match, check keyword
//				if (!bodytext.compare(i-hashlimit, keywords[j].length(), keywords[j])) {
//					cout << "MATCHED" << endl;
//					exit(EXIT_SUCCESS);
//				}
//			}
//		}								//Realtime Hash Updating
//		dochash = dochash - bodytext[i-hashlimit] + bodytext[i];
//	}
//
//	for (unsigned i = 0; i < keywords.size(); i++)	//Shows Keywords On Fail
//		cout << keywords[i] << " " << hashes[i] << endl;
//
//	cout << "NO MATCHES FOUND" << endl;	//Failure
//	exit(EXIT_FAILURE);
//}
