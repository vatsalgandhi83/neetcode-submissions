/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // 0(s) 5(s) 10(e) 15(s) 20(e) 40(e)
        map<int, int> mp;
        for(int i = 0; i < intervals.size(); i++) {
            mp[intervals[i].start]++;
            mp[intervals[i].end]--;
        }

        int res = 0;
        int currRooms = 0;

        for(auto i : mp) {
            currRooms += i.second;
            res = max(currRooms, res);
        }
        
        return res;
    }
};
