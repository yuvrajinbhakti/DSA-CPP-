class Solution {
private:
    int helper(vector<int>& nums, int ind, int lastind,
               vector<vector<int>>& memo) {

        if(ind == nums.size()) return 0;

        if(memo[ind][lastind+1] != -1)
            return memo[ind][lastind+1];

        int notTake = helper(nums, ind+1, lastind, memo);

        int take = 0;
        if(lastind == -1 || nums[ind] > nums[lastind]){
            take = 1 + helper(nums, ind+1, ind, memo);
        }

        return memo[ind][lastind+1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return helper(nums, 0, -1, memo);
    }
};
