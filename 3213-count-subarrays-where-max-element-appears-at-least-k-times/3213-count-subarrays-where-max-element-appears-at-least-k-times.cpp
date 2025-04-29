class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi=*max_element(nums.begin(),nums.end()),count=0;
        long long int left=0,right=0,ans=0;
        while(right<nums.size()){
            if(nums[right]==maxi)count++;
            while(count>=k){
                if(nums[left]==maxi)count--;
                left++;
                ans+=nums.size()-right;
            }
            right++;
        }
    return ans;
    }
};