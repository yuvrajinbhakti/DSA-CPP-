/*
Intuition:
The same problems as "Climbing Stairs" or "Fibo Sequence".

Explanation:
dp[i] is the probability that we get points i at some moment.
In another word:
1 - dp[i]is the probability that we skip the points i.

The do equation is that:
dp[i] = sum(last W dp values) / W

To get Wsum = sum(last W dp values),
we can maintain a sliding window with size at most W.


Time Complexity:
Time O(N)
Space O(N), can be improve to O(W)
*/
class Solution {
public:
        double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K) Wsum += dp[i]; else res += dp[i];
            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
    }
};