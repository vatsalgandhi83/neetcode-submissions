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
        // map<int, int> mp;
        // for(int i = 0; i < intervals.size(); i++) {
        //     mp[intervals[i].start]++;
        //     mp[intervals[i].end]--;
        // }

        // int res = 0;
        // int currRooms = 0;

        // for(auto i : mp) {
        //     currRooms += i.second;
        //     res = max(currRooms, res);
        // }
        
        // return res;

        // Approach II

        vector<int> startTimes;
        vector<int> endTimes;

        for(int i = 0; i < intervals.size(); i++) {
            startTimes.push_back(intervals[i].start);
            endTimes.push_back(intervals[i].end);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int i = 0, j = 0;

        int res = 0;
        int currRooms = 0;

        while (i < intervals.size()) {
            if (startTimes[i] < endTimes[j]) {
                currRooms += 1;
                res = max(res, currRooms);
                i += 1;
            } else {
                currRooms -= 1;
                j += 1;
            }
        }
        return res;

    }
};
