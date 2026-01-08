//method1
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


//method 2
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> freq(n + 1, 0);

//         for (int num : nums) {
//             freq[num]++;
//         }

//         int duplicate = 0, missing = 0;
//         for (int i = 1; i <= n; i++) {
//             if (freq[i] == 2) duplicate = i;
//             if (freq[i] == 0) missing = i;
//         }

//         return {duplicate, missing};
//     }
// };


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


//most optimized approach

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        // xorAll will store XOR of numbers from 1 to n
        int xorAll = 0;

        // xorArray will store XOR of all elements in nums
        int xorArray = 0;

        // XOR all expected numbers (1 to n)
        // Result: 1 ^ 2 ^ 3 ^ ... ^ n
        for (int i = 1; i <= n; i++) {
            xorAll ^= i;
        }

        // XOR all actual numbers present in the array
        // Result: nums[0] ^ nums[1] ^ ... ^ nums[n-1]
        for (int num : nums) {
            xorArray ^= num;
        }

        // XORing both cancels out all correct numbers
        // Left with: duplicate ^ missing
        int xorResult = xorArray ^ xorAll;

        // Get the rightmost set bit of xorResult
        // This bit differs between duplicate and missing
        int rightmostSetBit = xorResult & -xorResult;

        // These will store XOR results of two groups
        int xorSet = 0;
        int xorNotSet = 0;

        // Divide numbers from 1 to n into two groups
        // based on the rightmostSetBit
        for (int i = 1; i <= n; i++) {
            if (i & rightmostSetBit) {
                xorSet ^= i;        // bit is set
            } else {
                xorNotSet ^= i;     // bit is not set
            }
        }

        // Divide array elements into the same two groups
        for (int num : nums) {
            if (num & rightmostSetBit) {
                xorSet ^= num;      // bit is set
            } else {
                xorNotSet ^= num;   // bit is not set
            }
        }

        // At this point:
        // xorSet and xorNotSet are the two numbers:
        // one is duplicate, the other is missing

        // Check which one appears in the array
        // The one that exists is the duplicate
        for (int num : nums) {
            if (num == xorSet) {
                return {xorSet, xorNotSet}; // {duplicate, missing}
            }
        }

        // Otherwise, xorNotSet is duplicate
        return {xorNotSet, xorSet};
    }
};
