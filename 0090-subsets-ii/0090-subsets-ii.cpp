class Solution {
    private:
    void GiveAllSubsets(vector<int> & nums,set<vector<int>> &allSubsets,vector<int> & subset,int index){
        if(index>=nums.size()){
            allSubsets.insert(subset);
            return;
        }
        //take
        subset.push_back(nums[index]);
        GiveAllSubsets(nums,allSubsets,subset,index+1);
        subset.pop_back();
        //not take
        GiveAllSubsets(nums,allSubsets,subset,index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
set<vector<int>> allSubsets;
vector<int> subset;
int index=0;
sort(nums.begin(),nums.end());
GiveAllSubsets(nums,allSubsets,subset,index);
vector<vector<int>> ans;
for(auto it: allSubsets){
    ans.push_back(it);
}
return ans;
    }
};