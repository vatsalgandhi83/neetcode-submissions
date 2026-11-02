class Solution {
private:
    int search(int left, int right, vector<int>& nums) {
        if (left == right) return nums[left];
        if (nums[left] <= nums[right]) return nums[left];
        
        int mid = (left + right) / 2;
        
        if (nums[mid] < nums[right]) {
            return search(left, mid, nums);
        } else {
            return search(mid + 1, right, nums);
        }
    }

public:
    int findMin(vector<int>& nums) {
        return search(0, nums.size() - 1, nums);
    }
};
