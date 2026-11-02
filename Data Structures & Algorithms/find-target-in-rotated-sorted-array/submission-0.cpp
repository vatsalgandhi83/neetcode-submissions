class Solution {
private:
    int binarySearch(int left, int right, vector<int>& nums, int target) {
        if (left == right) {
            return nums[left] == target ? left : -1;
        } 

        if (nums[left] == target) {
            return left;
        }

        if (nums[right] == target) {
            return right;
        }

        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                return binarySearch(left, mid - 1, nums, target);
            } else {
                return binarySearch(mid + 1, right, nums, target);
            }
        } 
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                return binarySearch(mid + 1, right, nums, target);
            } else {
                return binarySearch(left, mid - 1, nums, target);
            }
        } 

    }
public:
    int search(vector<int>& nums, int target) {
        // Recursion
        // return binarySearch(0, nums.size() - 1, nums, target);


        // Iterative
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            if (left == right) {
                return nums[left] == target ? left : -1;
            }

            if (nums[left] == target) return left;
            if (nums[right] == target) return right;

            int mid = (left + right)/2;

            if (nums[mid] == target) return mid;

            // check if left is sorted
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target <= nums[mid]) 
                    right = mid;
                else 
                    left = mid + 1;
            }

            // check if right is sorted
            else {
                if (target >= nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }

        }
        return -1;

    }
};