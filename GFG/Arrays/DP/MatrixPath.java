import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static int getMax(int a, int b, int c)
    {
            if (a >= b && a >= c) return a;
            if (b >= a && b >= c) return b;
            if (c >= a && c >= b) return c;
            return 0;
        }
    
    static void maxPath(int matrix[][], int n)
    {
            int [][]sol = new int[n][n];
            int i, j, maxPathVal = 0;
            for (i = 0; i < n; i++)
            sol[0][i] = matrix[0][i];
            for (i = 1; i < n; i++) {
	          for (j = 0; j < n; j++) {
			if (j == 0)
				sol[i][j] = matrix[i][j] + getMax(sol[i - 1][0],
					       			sol[i - 1][1], -1);
			else if (j == n-1)
			        sol[i][j] = matrix[i][j] + getMax(sol[i - 1][n - 2],
							   	sol[i - 1][n - 1], -1);
			else
			        sol[i][j] = matrix[i][j] + getMax(sol[i - 1][j],
					       			sol[i - 1][j - 1],
								sol[i - 1][j + 1]);
			}
	    }
            maxPathVal = 0;
            for ( i = 0; i < n; i++)
                maxPathVal = sol[i][n - 1] >= maxPathVal ?
                                    sol[i][n - 1] : maxPathVal;
            System.out.println(maxPathVal);
      }
      public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    int [][]arr = new int[20][20];
	    // One by one run for all input test cases
            while (t > 0) {
		//                     // Input the size of the array
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
		          arr[i][j] = sc.nextInt();
		        }
		}
		maxPath(arr, n);
		t--;
	    }
       }
}
