class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> concatenatedArr(nums.size()*2);
        for(int i=0;i<nums.size();i++){
            concatenatedArr[i] = nums[i];
        }
        for(int i=0;i<nums.size();i++){
            concatenatedArr[nums.size()+i] = nums[i];
        }
        return concatenatedArr;
    }
};