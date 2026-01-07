// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> concatenatedArr(n*2);
//         for(int i=0;i<n;i++){
//             concatenatedArr[i] = nums[i];
//             concatenatedArr[n+i] = nums[i];
//         }
//         return concatenatedArr;
//     }
// };


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
    vector<int> result;
    result.reserve(nums.size()*2);
    result.insert(result.end(),nums.begin(),nums.end());
    result.insert(result.end(),nums.begin(),nums.end());
    return result;
    }
};