class Solution {
public:

    /* ============================================================
       METHOD 1: Pure Recursion
       Time Complexity: O(2^(n+m))  ❌
       Space Complexity: O(n+m) (recursion stack)
       ============================================================ */
    int recursion(string &s1, string &s2, int i, int j) {

        // Base case: if one string ends
        if (i == s1.size() || j == s2.size()) {
            int cost = 0;
            for (int x = i; x < s1.size(); x++) cost += s1[x];
            for (int x = j; x < s2.size(); x++) cost += s2[x];
            return cost;
        }

        // If characters match, move both pointers
        if (s1[i] == s2[j]) {
            return recursion(s1, s2, i + 1, j + 1);
        }

        // Delete either from s1 or s2
        int cost1 = s1[i] + recursion(s1, s2, i + 1, j);
        int cost2 = s2[j] + recursion(s1, s2, i, j + 1);

        return min(cost1, cost2);
    }

    /* ============================================================
       METHOD 2: Top-Down DP (Memoization)
       Time Complexity: O(n × m)
       Space Complexity: O(n × m) + recursion stack
       ============================================================ */
    int topdown(string &s1, string &s2, int i, int j,
                vector<vector<int>> &dp) {

        if (dp[i][j] != -1) return dp[i][j];

        // Base case
        if (i == s1.size() || j == s2.size()) {
            int cost = 0;
            for (int x = i; x < s1.size(); x++) cost += s1[x];
            for (int x = j; x < s2.size(); x++) cost += s2[x];
            return dp[i][j] = cost;
        }

        if (s1[i] == s2[j]) {
            return dp[i][j] = topdown(s1, s2, i + 1, j + 1, dp);
        }

        int cost1 = s1[i] + topdown(s1, s2, i + 1, j, dp);
        int cost2 = s2[j] + topdown(s1, s2, i, j + 1, dp);

        return dp[i][j] = min(cost1, cost2);
    }

    /* ============================================================
       METHOD 3: Bottom-Up DP (Tabulation)
       Time Complexity: O(n × m)
       Space Complexity: O(n × m)
       ============================================================ */
    int bottomup(string &s1, string &s2) {

        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case initialization
        for (int i = n - 1; i >= 0; i--)
            dp[i][m] = s1[i] + dp[i + 1][m];

        for (int j = m - 1; j >= 0; j--)
            dp[n][j] = s2[j] + dp[n][j + 1];

        // Fill DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = min(
                        s1[i] + dp[i + 1][j],
                        s2[j] + dp[i][j + 1]
                    );
            }
        }

        return dp[0][0];
    }

    /* ============================================================
       METHOD 4: Space Optimized DP ⭐ (BEST)
       Time Complexity: O(n × m)
       Space Complexity: O(min(n, m))
       ============================================================ */
    int spaceOptimized(string s1, string s2) {

        if (s1.size() < s2.size()) swap(s1, s2);

        int n = s1.size(), m = s2.size();
        vector<int> next(m + 1, 0), curr(m + 1, 0);

        // Base case
        for (int j = m - 1; j >= 0; j--)
            next[j] = s2[j] + next[j + 1];

        for (int i = n - 1; i >= 0; i--) {
            curr[m] = s1[i] + next[m];

            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    curr[j] = next[j + 1];
                else
                    curr[j] = min(
                        s1[i] + next[j],
                        s2[j] + curr[j + 1]
                    );
            }
            next = curr;
        }

        return next[0];
    }

    /* ============================================================
       Driver Function
       ============================================================ */
    int minimumDeleteSum(string s1, string s2) {

        // Uncomment to test different methods

        // Method 1: Recursion
        // return recursion(s1, s2, 0, 0);

        // Method 2: Top-Down DP
        // vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        // return topdown(s1, s2, 0, 0, dp);

        // Method 3: Bottom-Up DP
        // return bottomup(s1, s2);

        // Method 4: Space Optimized DP (BEST)
        return spaceOptimized(s1, s2);
    }
};
