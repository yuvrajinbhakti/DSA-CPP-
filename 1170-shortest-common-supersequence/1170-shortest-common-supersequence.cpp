class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //step1 -> find lcs(longes common subsequence) using dp
        int m=str1.length(),n=str2.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        //fill dp table
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    //step2 ->construct shortest common supersequence
int i=m,j=n;
string res="";
while(i>0 && j>0){
    //if chars are same, add it once
    if(str1[i-1]==str2[j-1]){
        res.push_back(str1[i-1]);
        i--;
        j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
        //if coming from top has higher value, take char from str1
res.push_back(str1[i-1]);
i--;
    }
    else{
        res.push_back(str2[j-1]);
        j--;
    }
}
//add any remaining chars
while(i>0){
    res.push_back(str1[i-1]);
    i--;
}
while(j>0){
    res.push_back(str2[j-1]);
    j--;
}
reverse(res.begin(),res.end());
return res;
    }
};