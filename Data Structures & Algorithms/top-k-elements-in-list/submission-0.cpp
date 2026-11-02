class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> freq_vectors(n);
        vector<int> result;
        cout << "aa1" << endl;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        cout << "aa2" << endl;
        for(auto i : mp) {
            freq_vectors[i.second - 1].push_back(i.first);
        }
        for(int i = freq_vectors.size() - 1; i >= 0; i--) {
            if(freq_vectors[i].size()) {
                cout << "aa3" << endl;
                for(auto j : freq_vectors[i]) {
                    result.push_back(j);
                    if (result.size() == k) {
                        return result;
                    }
                }
            }
        }
        return result;
    }
};