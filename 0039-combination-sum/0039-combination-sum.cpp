class Solution {
    private:
void helper(vector<vector<int>> &ans,vector<int> &candidates, int target ,vector<int> &v,int index,int &currSum){
    if(currSum>target)return;
if(index>=candidates.size()){
if(currSum==target){ans.push_back(v);return;}
return ;
}
//take
v.push_back(candidates[index]);
currSum+=candidates[index];
        helper(ans,candidates,target,v,index,currSum);
v.pop_back();
currSum-=candidates[index];

//not take
        helper(ans,candidates,target,v,index+1,currSum);

}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int currSum=0;
        helper(ans,candidates,target,v,0,currSum);
        return ans;
    }
};