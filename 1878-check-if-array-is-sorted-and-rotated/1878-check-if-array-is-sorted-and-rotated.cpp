class Solution {
    bool helper(int i,vector<int> &nums){
        vector<int> v1,v2;
for(int j=0;j<=i;j++){
    v1.push_back(nums[j]);
}
for(int j=i+1;j<nums.size();j++){
    v2.push_back(nums[j]);
}
vector<int> v;
for(int j=0;j<v2.size();j++){
v.push_back(v2[j]);
}

for(int j=0;j<v1.size();j++){
v.push_back(v1[j]);
}
for(int j=0;j<v.size()-1;j++){
    if(v[j]>v[j+1])return false;
    }
    return true;
}

public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
return helper(i,nums);
            }
        }
        return true;
    }
};