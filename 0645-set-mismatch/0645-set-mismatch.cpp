class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mpp;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(mpp.find(nums[i])!=mpp.end()){
                ans.push_back(nums[i]);
            }
            // mpp.insert(nums[i]);
            mpp[nums[i]]++;
        }
        for(int i=0;i<size;i++){
            if(mpp.find(i+1)==mpp.end()){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};