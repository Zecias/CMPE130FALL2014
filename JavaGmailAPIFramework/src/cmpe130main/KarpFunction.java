package cmpe130main;

//	This Karp Function has not been tested

public class KarpFunction extends Key{
	
	/**
	 * @param	input_string	The string you want to search through
	 * @param	search_keys		The container of pre-sorted keywords to search for
	 * @return	A score from ~[-100] to ~[+100] based on the <Keys> database
	 */
	
	rank_t rankString(String input_string, keys search_keys) {
		rank_t rank = new rank_t();
		hash_t strhash = new hash_t();
		int i = 0;
		while (i < search_keys.maxlen - 1 && i < input_string.length()) {
			hash(strhash, input_string.charAt(i++), search_keys.maxlen);
		}
		for (; i < input_string.length(); i++) {
			hash(strhash, input_string.charAt(i), search_keys.maxlen);
			rank.ranks += rankThis(input_string, i, strhash, search_keys);
		}
		return rank;
	}
	
	// Use this to test
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
