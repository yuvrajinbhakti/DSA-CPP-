class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size=nums.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            int cnt=0;
            for(int j=0;j<size;j++){
                if(i!=j & nums[j]<nums[i] ){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};