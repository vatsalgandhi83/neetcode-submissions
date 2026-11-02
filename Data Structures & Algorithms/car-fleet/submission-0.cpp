class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, float>> cars;

        for (int i = 0; i < n; ++i) {
            float time = (float)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        stack<float> st;
        for (int i = n - 1; i >= 0; --i) {
            float time = cars[i].second;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};
