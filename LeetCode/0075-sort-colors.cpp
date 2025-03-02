class Solution {
// dutch national flag algorithm has been used
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if (nums[mid]==0){
                swap(nums[low],nums[mid]);
                low ++;
                mid ++;
            }
            else if (nums[mid]==1){
                mid ++;
            }
            else {
                swap (nums[mid],nums[high]);
                high --;
            }
        }
    }
};
