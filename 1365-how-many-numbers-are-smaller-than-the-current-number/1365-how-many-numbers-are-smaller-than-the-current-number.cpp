//T.C. = O(N^2),S.C. = O(N)
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int size=nums.size();
//         vector<int> ans(size);
//         for(int i=0;i<size;i++){
//             int cnt=0;
//             for(int j=0;j<size;j++){
//                 if( nums[j]<nums[i] ){
//                     cnt++;
//                 }
//             }
//             ans[i]=cnt;
//         }
//         return ans;
//     }
// };



// Time: O(n + k) → k = 101 ≈ constant
// Space: O(k) → constant
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Since nums[i] is between 0 and 100
        vector<int> freq(101, 0);

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Prefix sum:
        // freq[i] will store how many numbers are < i
        for (int i = 1; i <= 100; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> ans;
        for (int num : nums) {
            if (num == 0)
                ans.push_back(0);
            else
                ans.push_back(freq[num - 1]);
        }

        return ans;
    }
};
