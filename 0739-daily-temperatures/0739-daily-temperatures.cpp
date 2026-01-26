class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // ans[i] will store how many days after day i
        // we get a warmer temperature
        vector<int> ans(n, 0);

        // Stack will store indices of days
        // Temperatures at these indices are in decreasing order
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove all days that are NOT warmer than today
            // because they cannot be the answer for day i
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack is not empty, the top element is the
            // next day with a warmer temperature
            if (!st.empty()) {
                // st.top() gives the index of the next warmer day
                // i is the current day
                // difference = number of days to wait
                ans[i] = st.top() - i;
            }
            // If stack is empty, there is no warmer day in future
            // ans[i] remains 0

            // Push current day index onto the stack
            st.push(i);
        }

        return ans;
    }
};
