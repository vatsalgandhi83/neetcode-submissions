class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        int i = 0;
        vector<int> result;
        for(; i < k; i++) {
            while (dq.size() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }

        // 1 3 -1 -3 5 3 5 7  -> 1 
        result.push_back(dq.front());
        for(; i < n; i++) {
            while (dq.size() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if (dq.front() == nums[i - k]) {
                dq.pop_front();
            }
            result.push_back(dq.front());
        }
        return result;
    }
};