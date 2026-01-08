// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         vector<int> ans;
//         map<int,int> mpp;
//         int size=nums.size();
//         for(int i=0;i<size;i++){
//             if(mpp.find(nums[i])!=mpp.end()){
//                 ans.push_back(nums[i]);
//             }

//             mpp[nums[i]]++;
//         }
//         for(int i=0;i<size;i++){
//             if(mpp.find(i+1)==mpp.end()){
//                 ans.push_back(i+1);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int num : nums) {
            freq[num]++;
        }

        int duplicate = 0, missing = 0;
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) duplicate = i;
            if (freq[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};


/* //only if inplace allowed 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, missing = -1;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                duplicate = abs(nums[i]);
            else
                nums[idx] = -nums[idx];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
*/