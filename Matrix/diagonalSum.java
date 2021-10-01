//https://leetcode.com/problems/matrix-diagonal-sum/

import java.util.Arrays;
import java.util.Scanner;

public class diagonalSum {
    public static int buildArray(int[][] mat) {
        int sum = 0;
        int n = mat.length;
        for (int i=0; i<n; i++) {
            sum += mat[i][i]; 
            sum += mat[n-1-i][i];
        }
        if(n%2==0) {
            return sum;
        }
        else {
            return sum-mat[n/2][n/2];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter rows of the array: ");
        int m = sc.nextInt();
        System.out.println("Enter cols of the array: ");
        int n = sc.nextInt();
        int arr[][] = new int[m][n];
        System.out.println("Enter the arrays");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.println(Arrays.deepToString(arr));
        System.out.println(buildArray(arr));
        sc.close();
    }
}
