class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0; // indicates first 1.. index 0 to low - 1 is all 0s
        int mid = 0; // indicates the beginning of unsorted part. low to mid-1 is all 1s
        int high = nums.size() - 1; // indicates end of unsorted part. high+1 to n-1 is all 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};