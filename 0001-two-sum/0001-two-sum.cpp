class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // brute force -> T.C. O(N^2) -> for each ele check if target - ele exist
        // sorting -> T.C. O( N Log N), S.C. -> O(1)
       // using map -> T.C. O(N), S.C. -> O(N)

        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target - nums[i]) ==mpp.end()){
                mpp.insert({nums[i],i});
            }
            else
            return {i,mpp[target-nums[i]]};
        }
        return {-1,-1};
    }
};