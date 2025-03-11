class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0,j=0,count=0;
        unordered_map<char,int> mpp;
        while(j<n){
            mpp[s[j]]++;
            while(mpp['a']>=1 && mpp['b']>=1. && mpp['c']>=1){
                count+=(n-j);

                //shrinking the window
                mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};