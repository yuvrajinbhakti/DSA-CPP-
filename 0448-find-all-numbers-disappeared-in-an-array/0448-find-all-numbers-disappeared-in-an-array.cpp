class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int size=nums.size();
        vector<int> freq(size+1);
        for(int i=0;i<size;i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<freq.size();i++){
            if(freq[i]==0)ans.push_back(i);
        }
        return ans;
    }
};