class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;          // stores function IDs
        int prevTime = 0;       // last processed timestamp

        for (const string& log : logs) {
            // Parse log: id:type:time
            int firstColon = log.find(':');
            int secondColon = log.find(':', firstColon + 1);

            int id = stoi(log.substr(0, firstColon));
            string type = log.substr(firstColon + 1, secondColon - firstColon - 1);
            int time = stoi(log.substr(secondColon + 1));

            if (type == "start") {
                // Pause currently running function
                if (!st.empty()) {
                    result[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } 
            else { // "end"
                // Finish current function
                result[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return result;
    }
};
