package cmpe130main;
//import java.math.BigInteger;		// Java's Equivalent to long long

public class HashFunction{
	
	public static class hash_t{
		public long hasher;
		
		public hash_t(){
			hasher = 0;
		}
		
	}
	
	
	public static int hash_t_len_max = 6;
//	public static int lhash_t_len_max = 12;
	
	private static long hash_t_mask_max = 1073741823;
	
	
	/**
	 * This function creates a perfect alphabet hash such that:
	 * Example: hash("ab") != hash("ba")
	 * Example: hash("Ab") == hash("aB")
	 * Usage: [ hash(empty_hash, 'a', 3); ]
	 *
	 * @param	hash	The <hash> to append <characters> to
	 * @param	append	The single <character> from aA~zZ to append to <hash>
	 * @param	len		The max character <length> the <hash> contains [max == 6]
	 * @return	A 30 bit wide hash containing the hash of <length> characters
	 */
	
	public static void hash(hash_t hash, char append, int len) {
		hash.hasher = ((hash.hasher << 5) | (append & 0b11111))
			& (hash_t_mask_max >> (hash_t_len_max - len) * 5);
	}
	
	
	/**
	 * This function creates a perfect alphabet hash such that:
	 * Example: lhash("ab") != lhash("ba")
	 * Example: lhash("Ab") == lhash("aB")
	 * Usage: [ lhash(empty_hash, 'a', 9); ]
	 *
	 * @param	hash	The <hash> to append <characters> to
	 * @param	append	The single <character> from aA~zZ to append to <hash>
	 * @param	len		The max character <length> the <hash> contains [max == 12]
	 * @return	A 60 bit wide hash containing the hash of <length> characters
	 */
	
	
//	public static void lhash(hash_t hash, char append, int len) {
//		hash = ((hash << 5) | (append & 0b11111))
//			& (lhash_t_mask_max >> (lhash_t_len_max - len) * 5);
//	}
	
	
	// This is the Test Function to prove that it works correctly
	public static void main(String[] args){
		
		hash_t hashed = new hash_t();
		
		hash(hashed, 'A', 6);
		hash(hashed, 'b', 6);
		hash(hashed, 'C', 6);
		hash(hashed, 'd', 6);
		hash(hashed, 'E', 6);
		hash(hashed, 'f', 6);
		hash(hashed, 'G', 6);
		
		System.out.println(hashed.hasher);
		
			
	}
	
}
