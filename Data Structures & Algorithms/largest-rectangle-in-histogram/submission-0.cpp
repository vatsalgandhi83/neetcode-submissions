class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                
                int currentHeight = heights[st.top()]; // height for which maxArea is to calc
                int nseIndex = i;
                st.pop();
                int pseIndex = st.empty() ? -1 : st.top(); 
                int currentWidth = nseIndex - pseIndex - 1;
                maxArea = max(maxArea, currentHeight * currentWidth);
            }
            st.push(i);
        }

        // for elements present in stack, nseIndex => 'n'
        while (!st.empty()) {
            int currentHeight = heights[st.top()];
            int nseIndex = n;
            st.pop();
            int pseIndex = st.empty() ? -1 : st.top();
            int currentWidth = nseIndex - pseIndex - 1;
            maxArea = max(maxArea, currentHeight * currentWidth);
        }

        return maxArea;   
    }
};