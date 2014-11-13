package cmpe130main;
import java.util.Vector;
import java.io.IOException;
import java.io.FileReader;
import java.io.BufferedReader;

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
		Vector<String> keyword = new Vector<String>(32);
		Vector<rank_t> rank = new Vector<rank_t>(32);
		Vector<hash_t> hash = new Vector<hash_t>(32);
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
	Boolean load(keys keyset, String filename) {
		
		public String[] OpenFile() throws IOException{
			FileReader in = new FileReader(filename);
			BufferedReader textReader = new BufferedReader(in);
			
			String line;
			while((line = textReader.readLine()) != null){
				String a;
				a = textReader.readLine();
				
				int delimination_index = a.indexOf('|');
				int hash_index = a.charAt(delimination_index + 1) & 31;
				int word_length = a.length() - delimination_index - 2;
				
				keyset.keyword.add(hash_index,a.substring(
						delimination_index + 1, word_length));
				
				
				/* this needs to be fixed somehow.
				 * 
				*  The problem here is because Brandon likes defining his own types
				*  Because he wanted to be complex and make rank_t instead of just using long,
				*  the error below is present.
				*/
				keyset.rank.add(hash_index, Integer.parseInt(a.substring(0, delimination_index)));
				
				if (word_length < keyset.maxlen){
					keyset.maxlen = word_length;}
			}
			
			textReader.close();
			
		}
		
//	
//		
//		if (in.fail())
//			return false;
//		while (!in.eof()) {
//			std::string str;
//			getline(in, str);
//			unsigned delimination_index = str.find('|');
//			unsigned hash_index = str[delimination_index + 1];
//			unsigned word_length = str.length() - delimination_index - 2;
//			keyset.keyword[hash_index].push_back(str.substr(
//					delimination_index + 1, word_length));
//			keyset.rank[hash_index].push_back(std::atoi(
//					str.substr(0, delimination_index).c_str()));
//			if (word_length < keyset.maxlen)
//				keyset.maxlen = word_length;
//		}
//		for (unsigned i = 0; i < 32; i++) {
//			/* Bubbly Sort */
//			if (keyset.keyword[i].size() > 1)
//				for (unsigned top = 0,
//						bot = keyset.keyword[i].size() - 1,
//						next_top = keyset.keyword[i].size() - 1;
//						top < keyset.keyword[i].size() - 1;
//						top = next_top,
//						next_top = bot = keyset.keyword[i].size() - 1)
//					for (; top < bot; bot--)
//						if (keyset.keyword[i][bot - 1].compare(
//								keyset.keyword[i][bot]) > 0)
//							std::swap(
//									keyset.keyword[i][bot],
//									keyset.keyword[i][bot - 1]),
//							std::swap(
//									keyset.rank[i][bot],
//									keyset.rank[i][bot - 1]),
//							next_top = bot;
//			keyset.hash[i].resize(keyset.keyword[i].size());
//			for (unsigned v = 0; v < keyset.keyword[i].size(); v++)
//				for (unsigned s = 0; s < keyset.maxlen; s++)
//					hash(keyset.hash[i][v], keyset.keyword[i][v][s], keyset.maxlen);
//		}
//		return true;
//	}


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
