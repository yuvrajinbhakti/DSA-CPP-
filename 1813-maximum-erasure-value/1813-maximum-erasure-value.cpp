class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> seen;
        int left=0,currentSum=0,maxSum=0;
        for(int right=0;right<n;++right){
            while(seen.find(nums[right])!=seen.end()){
                currentSum-=nums[left];
                seen.erase(nums[left]);
                ++left;
            }
            currentSum+=nums[right];
            seen.insert(nums[right]);
            maxSum=max(maxSum,currentSum);
        }
        return maxSum;
    }
};