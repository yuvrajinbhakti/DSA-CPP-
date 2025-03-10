// class Solution {
//     private:
//     int helper(string text1,string text2,int i,int j){
// //base case
// if(i<0 || j<0)return 0;

// //if equal
// if(text1[i]==text2[j]){
//     return 1+helper(text1,text2,i-1,j-1);
// }

// //if not equal
// return max(helper(text1,text2,i-1,j),helper(text1,text2,i,j-1));


//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         return helper(text1,text2,text1.size()-1,text2.size()-1);
//     }
// };




//memoization

// class Solution {
//     private:
//     int helper(string text1,string text2,int i,int j,vector<vector<int>> &dp){
// //base case
// if(i<0 || j<0)return 0;
// if(dp[i][j]!=-1)return dp[i][j];
// //if equal
// if(text1[i]==text2[j]){
//     return dp[i][j]=1+helper(text1,text2,i-1,j-1,dp);
// }

// //if not equal
// return dp[i][j]=max(helper(text1,text2,i-1,j,dp),helper(text1,text2,i,j-1,dp));
//     }

// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size(),m=text2.size();
//         vector<vector<int>> dp(n,vector<int> (m,-1));
//         return helper(text1,text2,n-1,m-1,dp);
//     }
// };





//tabulation 
// class Solution {
// public:
//     int longestCommonSubsequence(string s1, string s2) {
//        int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

//     // Initialize the base cases
//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = 0;
//     }
//     for (int i = 0; i <= m; i++) {
//         dp[0][i] = 0;
//     }

//     // Fill in the DP table to calculate the length of LCS
//     for (int ind1 = 1; ind1 <= n; ind1++) {
//         for (int ind2 = 1; ind2 <= m; ind2++) {
//             if (s1[ind1 - 1] == s2[ind2 - 1])
//                 dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
//             else
//                 dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
//         }
//     }

//     return dp[n][m]; // Return the length of the Longest Common Subsequence

//     }
// };




//space optimizaion 
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
     
    int n = s1.size();
    int m = s2.size();

    // Initialize two vectors to store the current and previous rows of the DP table
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base case is covered as we have initialized the prev and cur vectors to 0.

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]); // Characters don't match, consider the maximum from above or left
        }
        prev = cur; // Update the previous row with the current row
    }

    return prev[m]; // Return the length of the Longest Common Subsequence
}
};

