package cmpe130main;
import java.util.Vector;

public class Key extends HashFunction{

	public static class rank_t{
		public long ranks;
		
		public rank_t(){
			ranks = 0;
		}
		
	}
	
	/**
	 * @param	keyword	An array of POINTERS to ARRAYS of keyword strings
	 * @param	rank	An array of POINTERS to ARRAYS of keyword worth
	 * @param	hash	An array of POINTERS to ARRAYS of keyword hashes
	 * @param	maxlen	The maximum character <length> of the <hash>es
	 * @note	indexes shall be defined by the 1st character of the hash
	 */
	
	public static class keys {
		vector<string> keyword[32];
		vector<rank_t> rank[32];
		vector<hash_t> hash[32];
		int maxlen = hash_t_len_max;
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
	bool load(keys keyset, char const* filename);

	/**
	 * Binary Hash Table Search
	 * @param	str		The input string
	 * @param	begin	The first string index hashed
	 * @param	input	The input string's <hash> to compare
	 * @param	keyset	The set of pre-sorted keywords to compare <hash> to
	 * @return	The rank associated with the longest keyword matched
	 * @return	0 when no match is found
	 */
	int rankThis(String str, int begin, hash_t input, keys keyset);

	/**
	 * @param	keyword	An array of POINTERS to ARRAYS of keyword strings
	 * @param	rank	An array of POINTERS to ARRAYS of keyword worth
	 * @param	hash	An array of POINTERS to ARRAYS of keyword long hashes
	 * @param	maxlen	The maximum character <length> of the <hash>es
	 */
//	public static class lkeys {
//		vector<string> keyword[32];
//		vector<rank_t> rank[32];
//		vector<lhash_t> hash[32];
//		int maxlen = lhash_t_len_max;
//	};
	
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
