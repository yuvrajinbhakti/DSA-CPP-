//recursion
// class Solution {
//     private:
//     int helper(string text1,string text2,int m,int n){
//         if(m<0 || n<0)return 0;

//         if(text1[m]==text2[n])return 1+helper(text1,text2,m-1,n-1);
//         int left=helper(text1,text2,m-1,n);
//         int right=helper(text1,text2,m,n-1);
//         return max(left,right);
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         return helper(text1,text2,text1.size()-1,text2.size()-1);
//     }
// };

//memoization
// class Solution {
//     private:
//     int helper(string text1,string text2,int m,int n,vector<vector<int>> &dp){
//         if(m<0 || n<0)return 0;
// if(dp[m][n]!=-1)return dp[m][n];
//         if(text1[m]==text2[n])return 1+helper(text1,text2,m-1,n-1,dp);
//         int left=helper(text1,text2,m-1,n,dp);
//         int right=helper(text1,text2,m,n-1,dp);
//         return dp[m][n]=max(left,right);
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size(),n=text2.size();
//         vector<vector<int> > dp(m,vector<int>(n,-1));
//         return helper(text1,text2,m-1,n-1,dp);
//     }
// };

//tabulation
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
        
        //initialize base case
        for(int i=0;i<=m;i++)dp[i][0]=0;
        for(int i=0;i<=n;i++)dp[0][i]=0;

        //fill dp table to calculate length of LCS
        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s1[ind1-1]==s2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1]; //char match
                else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]); //char don't match
            }
        }
        return dp[m][n];
    }
};