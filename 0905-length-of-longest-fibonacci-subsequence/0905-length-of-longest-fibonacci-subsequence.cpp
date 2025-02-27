class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n=A.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++)mpp[A[i]]=i;
        vector<vector<int>> dp(n,vector<int>(n,2));
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(mpp.find(A[j]-A[i])!=mpp.end() and mpp[A[j]-A[i]]<i){
                    dp[i][j]=max(dp[i][j],dp[mpp[A[j]-A[i]]][i]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return (ans==2)?0:ans;
    }
};