class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> umap;

    string search(const vector<pair<int, string>>& pairVector, int timestamp) {
        int n = pairVector.size();
        // cout << "n: " << n << endl;
        int left = 0, right = n - 1;
        string result;
        while (left <= right) {
            // long mid = (left + right)/2; // use either this
            int mid = left + (right - left) / 2; // or use this to prevent integer overflow.
            // cout << mid << endl;
            if (pairVector[mid].first == timestamp) {
                return pairVector[mid].second;
            } else if (pairVector[mid].first < timestamp) {
                result = pairVector[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        return search(umap[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */