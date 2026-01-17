class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int AllNumsXor=nums[0];
        for(int i=1;i<nums.size();i++){
            AllNumsXor=AllNumsXor^nums[i];
        }
        int XorTillN=0;
        for(int i=1;i<=nums.size();i++){
            XorTillN=XorTillN^i;
        }
        int ans=AllNumsXor^XorTillN;
        return ans;
    }
};