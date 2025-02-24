class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int maxi=0,cnt=0;
for(auto n:nums){
    if(n==1)maxi=max(++cnt,maxi);
    else cnt=0;
}
return maxi;
    }
};