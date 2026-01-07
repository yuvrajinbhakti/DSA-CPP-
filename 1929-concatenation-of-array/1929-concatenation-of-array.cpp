class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> concatenatedArr(n*2);
        for(int i=0;i<n;i++){
            concatenatedArr[i] = nums[i];
            concatenatedArr[n+i] = nums[i];
        }
        return concatenatedArr;
    }
};