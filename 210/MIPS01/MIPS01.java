public class MIPS01 {

	public static void main(String[] args) {
		int[] A = { 4, 3, 6, 7, 10, 34, 9, -3, 4, 1 };
		int i, sum = 0;
		
		for (i = 0; i < 10; i++) {
			sum += A[i];
		}
		
		System.out.print(sum);
	}//main
}//class
