class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            mpp[ch]=i;
        }
        vector<int> res;
        int prev=-1;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            maxi=max(maxi,mpp[s[i]]);
            if(maxi==i){
                res.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return res;
    }
};