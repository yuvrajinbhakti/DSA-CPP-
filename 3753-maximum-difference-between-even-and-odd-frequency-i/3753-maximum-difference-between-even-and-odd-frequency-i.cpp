class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mpp;
        int minEven=INT_MAX,maxiOdd=0,ans=0;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(auto it:mpp){
            if(it.second%2==0)minEven=min(minEven,it.second);
            else maxiOdd=max(maxiOdd,it.second);
        }
        return maxiOdd-minEven;
    }
};