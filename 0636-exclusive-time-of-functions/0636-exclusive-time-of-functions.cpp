/*
Since the CPU is single-threaded, function calls naturally form a call stack.

We process logs in order and use a stack to track the currently executing function.

A prevTime pointer helps calculate how much time has passed since the last event.

When a function starts, we pause the previously running function and record its time.

When a function ends, we finalize its execution time (handling inclusive end time with +1) and resume its caller.

This guarantees each function’s exclusive time is calculated correctly.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        // Result array: exclusive time for each function id
        vector<int> result(n, 0);

        // Stack to keep track of active function calls
        // Top of stack = currently running function
        stack<int> st;

        // Tracks the last timestamp we processed
        int prevTime = 0;

        // Process each log entry in order
        for (const string& log : logs) {

            // Parse log format: "id:start|end:timestamp"
            int firstColon = log.find(':');
            int secondColon = log.find(':', firstColon + 1);

            int id = stoi(log.substr(0, firstColon)); 
            string type = log.substr(firstColon + 1,
                                     secondColon - firstColon - 1);
            int time = stoi(log.substr(secondColon + 1));

            // Case 1: function starts
            if (type == "start") {

                // If another function was running,
                // add elapsed time to its exclusive time
                if (!st.empty()) {
                    result[st.top()] += time - prevTime;
                }

                // Push new function onto stack
                st.push(id);

                // Update last processed time
                prevTime = time;
            }

            // Case 2: function ends
            else {

                // Current function finishes execution
                // +1 because end time is inclusive
                result[st.top()] += time - prevTime + 1;

                // Remove finished function from stack
                st.pop();

                // Move prevTime to the next unit of time
                prevTime = time + 1;
            }
        }

        // Final exclusive times for all functions
        return result;
    }
};
