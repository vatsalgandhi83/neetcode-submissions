class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int result = (right - left) * min(height[left], height[right]);
        while (left < right) {
            result = max(result, min(height[left], height[right])*(right-left));
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};
