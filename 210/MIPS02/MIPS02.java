public class MIPS02 {

	public static void main(String[] args) {
		int[] A = {4, 3, 6, 7, 10, 34, 9, -3, 4, 1};
		
		for (int i = 1; i < 10; i++) {
			
			if (A[i] > A[i-1])
				System.out.print(A[i] + " ");
			
			else
				System.out.print(i + " ");
		}
	}//main
}//class
