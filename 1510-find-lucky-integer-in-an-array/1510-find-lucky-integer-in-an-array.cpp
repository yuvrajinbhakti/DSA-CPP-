class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int ans=-1;
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]]==arr[i])ans=max(ans,arr[i]);
        }
        return ans;
    }
};