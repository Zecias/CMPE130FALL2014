package cmpe130main;
//import java.math.BigInteger;		// Java's Equivalent to long long

public class HashFunction{
	
	public static class hash_t{
		public long hasher;
		
		public hash_t(){
			hasher = 0;
		}
		
	}
	
	
	private static int hash_t_len_max = 6;
//	private static int lhash_t_len_max = 12;
	
	private static long hash_t_mask_max = 1073741823;
	
	public static void hash(hash_t hash, char append, int len) {
		hash.hasher = ((hash.hasher << 5) | (append & 0b11111))
			& (hash_t_mask_max >> (hash_t_len_max - len) * 5);
	}
	
	
//	public static void lhash(hash_t hash, char append, int len) {
//		hash = ((hash << 5) | (append & 0b11111))
//			& (lhash_t_mask_max >> (lhash_t_len_max - len) * 5);
//	}
	
	
	/* This is the test Function */
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
