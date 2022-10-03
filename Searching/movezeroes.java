// 283. Move Zeroes
// Easy

// 9111

// 244

// Add to List

// Share
// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

// Follow up: Could you minimize the total number of operations done?

class Solution {
    public void moveZeroes(int[] nums) {
        int l = nums.length;
        int arr[] = new int[l];
        int index = 0;
        for (int i = 0; i < l; i++) {
            if (nums[i] != 0)
                arr[index++] = nums[i];
        }
        for (int i = index; i < l; i++) {
            arr[index] = 0;
        }
        for (int i = 0; i < l; i++) {
            nums[i] = arr[i];
        }

    }
}