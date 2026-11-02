class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int area = (right - left) * min(height[left], height[right]);

        while(left < right) {
            area = max(area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }

        }
        return area;

    }
};
