class Solution {

public:

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // Return the index of the single element
        if (nums[0] > nums[1]) return 0; // Return the index
        if (nums[n - 1] > nums[n - 2]) return n - 1; // Return the index
        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if mid is a peak
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            // If the element at mid is greater than the element to its left, then the peak element must be on the right half
            if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // This should never be reached if input meets problem constraints
    }
};
