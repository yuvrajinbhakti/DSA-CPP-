class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       //sort T.C. -> O(N*Log N), S.C. -> O(1)
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1])return nums[i];
        // }
        // return -1;

        //method2 -> use hashmap(or array)
        int n=nums.size();
            vector<int> v(n,-1);
            for(int i=0;i<n;i++){
                if(v[nums[i]]==-1){
                    v[nums[i]]=0;
                }
                else return nums[i];
            }
            return -1;
    }
};