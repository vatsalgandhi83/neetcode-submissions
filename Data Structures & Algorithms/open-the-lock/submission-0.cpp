class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());

        // if 0000 is itself a deadend then no way to open the lock. 
        if (deadendSet.count("0000")) {
            return -1;
        }

        if(target == "0000") {
            return 0;
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int turns = 0;
        while(!q.empty()) {
            int len = q.size();
            
            for(int i = 0; i < len; i++){
                string currStr = q.front();
                q.pop();

                if(deadendSet.find(currStr) != deadendSet.end()) {
                    continue;
                }

                if (currStr == target) {
                    return turns;
                }

                // For +1
                for(int j = 0; j < 4; j++) {
                    string temp = currStr;
                    char currChar = temp[j];
                    int currNum = currChar - '0';
                    currNum = (currNum + 1) % 10;
                    temp[j] = currNum + '0';

                    if(visited.find(temp) == visited.end()) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }

                // For -1
                for(int j = 0; j < 4; j++) {
                    string temp = currStr;
                    char currChar = temp[j];
                    int currNum = currChar - '0';
                    currNum = (currNum + 9) % 10;
                    temp[j] = currNum + '0';

                    if(visited.find(temp) == visited.end()) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }

            }
            turns++;
        }

        return -1;
    }
};