class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxElement = *max_element(piles.begin(), piles.end());
        int maxK = maxElement;
        int minK = 1;
        while(minK < maxK) {
            int currentK = (minK + maxK)/2; 
            int currentHours = 0;
            for(int i = 0; i < n; i++) {
                // currentHours += ceil(piles[i]*1.0/currentK);
                currentHours += (piles[i] + currentK - 1) / currentK;
            }
            if (currentHours <= h)
            {
                maxK = currentK;
            }
            else if (currentHours > h) {
                minK = currentK + 1;
            }
        }
        return maxK;

    }
};