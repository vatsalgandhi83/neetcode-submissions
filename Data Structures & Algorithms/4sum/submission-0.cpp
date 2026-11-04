class Solution {
private:
    vector<vector<int>> kSum(vector<int>& nums, long long target, int k, int startIndex) {
        int n = nums.size();
        vector<vector<int>> result;

        // handling the function recursively
        // base case: 2 sum with two pointers withing the given 
        if (k == 2) {
            int left = startIndex;
            int right = n - 1;

            while(left < right) {
                long long sum = 1LL * nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[left], nums[right]});

                    while(left < right && nums[left + 1] == nums[left]) {
                        left++;
                    }
                    while(left < right && nums[right - 1] == nums[right]) {
                        right--;
                    }

                    left++;
                    right--;

                } else if(sum < target) {
                    left++;
                } else { 
                    right--;
                }
            }
            return result;
        }

        for(int i = startIndex; i < n - k + 1; i++) {

            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }

            vector<vector<int>> smallerResults = kSum(nums, target - nums[i], k - 1, i + 1);

            for(auto smallerResult : smallerResults) {
                vector<int> temp = {nums[i]};
                temp.insert(temp.end(), smallerResult.begin(), smallerResult.end());
                result.push_back(temp);
            }

        }
        return result;

    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4, 0);
    }
};