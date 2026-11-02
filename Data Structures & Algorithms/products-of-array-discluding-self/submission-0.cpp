class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int runningProduct = 1;
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            res[i] *= runningProduct;
            runningProduct *= nums[i];
        }
        runningProduct = 1;
        for (int i = n-1; i >= 0; i--)
        {
            res[i] *= runningProduct;
            runningProduct *= nums[i];
        }
        return res;

        // int n = nums.size();
        // int product = 1, zc = 0;
        // vector<int> res(n, 0);
        // for (auto i : nums) {
        //     if (i == 0)
        //         zc++;
        //     else
        //         product *= i;
        // }
        // // cout << product << " " << zc << endl;
        // if (zc > 1)
        //     return res;
        // else {
        //     if (zc == 1) {
        //         for (int i = 0; i < n; i++)
        //             if (nums[i] == 0)
        //                 res[i] = product;
        //         return res;
        //     } else {
        //         for (int i = 0; i < n; i++)
        //             res[i] = product / nums[i];
        //         return res;
        //     }
        // }
    }
};