class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Remove all prices that can't be discounts
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // Apply discount if possible
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();

            // Push current price
            st.push(prices[i]);
        }

        return ans;
    }
};
