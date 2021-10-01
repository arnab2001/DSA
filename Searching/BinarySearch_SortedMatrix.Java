
//### Explanation : 

//###what is a sorted matrix? 
//Values in each row are sorted from left to right.
//The first value of each row is greater than the last value of the previous row.

//###Intuition behind the solution

//We will take 3 variables --> 
//Top will be pointed to the first row i.e 0
//Down will be pointed to the last row i.e. matrix.length-1
//Col will be the number of columns in the matrix i.e. matrix[0].length-1

//At first, we will be trying to find the "row" in which the target element is presented. If we are able to find the row then we will simply apply the BinarySearch in that row to find the element (as the matrix is sorted)

//How to find that desired row where the target is lying?  
//1. we will be running a while loop & the loop breaking condition will be the same as the BinarySearch algorithm i.e Top<=Down
//2. Then we will find the mid i.e. Top+(Down-Top)/2
//3.  If the target element is greater than the 1st element of the "mid" row (matrix[mid][0]<=target) & the target element is less than the last element of the "mid" row (matrix[mid][col]>=target), then we can definitely say that "mid" row is our desired row
//4. But what if the target element is less than the 1st element of the "mid" row (matrix[mid][0]>target), that means the element can not lie in that "mid" row & the rows lower than that "mid" row. So we will decrease "down" (down = down-1)
//5. What if the target element is greater than the last element of the "mid" row (matrix[mid][col]<target), that means the element can not lie in that "mid" row & the rows higher than that "mid" row. So we will increase "Top" (Top = Top+1)

import java.util.Arrays;

public class BinarySearch_SortedMatrix {

	static int [] findInMatrix (int [][]matrix, int target)
	{
		int top=0, down=matrix.length-1, col=matrix[0].length-1;
		while (top<=down)
		{
			int mid = top+(down-top)/2;
			if (matrix[mid][0]<=target && matrix[mid][col]>=target)
				return binarySearch(matrix, mid, target);
			if (matrix[mid][0]>target)
				down = mid-1;
			if (matrix[mid][col]<target)
				top = mid+1;
		}
		 return new int [] {-1,-1};	
	}
  
  
	public static int[] binarySearch(int[][] matrix, int rowIndex, int target) {
		int start = 0;
		int end = matrix.length-1;
		while (start<=end)
		{
			int mid = start+(end-start/2);
			if (matrix[rowIndex][mid]==target)
				return new int [] {rowIndex,mid};
			else if (matrix[rowIndex][mid]>target)
				end = mid-1;
			else 
				start = mid+1;
		}	
		return null;
	}
  
  
	public static void main(String[] args) {
		int [] [] matrix = {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{15,18,20,29}
				};
System.out.println(Arrays.toString(findInMatrix(matrix,1)));
	}
}
