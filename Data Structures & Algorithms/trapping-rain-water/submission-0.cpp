class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, leftMax = height[0];
        int right = n - 1, rightMax = height[n - 1];
        int result = 0;
        while (left < right) {
            result += max(0, leftMax - height[left]);
            result += max(0, rightMax - height[right]);
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return result;
    }
};
