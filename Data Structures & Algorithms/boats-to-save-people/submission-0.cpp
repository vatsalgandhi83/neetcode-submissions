class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n = people.size();
        int i = 0, j = n-1;
        // Each boat can carry at most two people. The greedy approach is:
        // 1. Sort the people by weight.
        sort(people.begin(), people.end());
        while(i <= j)
        {
            // 2. Pair the heaviest person with the lightest person if possible.
            // 3. Otherwise, the heaviest person goes alone.
            if(people[j] + people[i] <= limit)
                i++;
            j--;
            res++;
        }
        return res;
    }
};