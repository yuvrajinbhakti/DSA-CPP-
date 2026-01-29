// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int ans=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             int currProd=1;
//             for(int j=i;j<nums.size();j++){
//                 currProd=currProd*nums[j];
//                 ans=max(ans,currProd);
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     //O(N) time O(1) space

//     int maxProduct(vector<int> A) {
//         int n = A.size(), res = A[0], l = 0, r = 0;
//         for (int i = 0; i < n; i++) {
//             l =  (l ? l : 1) * A[i];
//             r =  (r ? r : 1) * A[n - 1 - i];
//             res = max(res, max(l, r));
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // maxProd: maximum product ending at current index
        // minProd: minimum product ending at current index
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // If current number is negative, max and min swap roles
            if (curr < 0) {
                swap(maxProd, minProd);
            }

            // Either start new subarray or extend previous one
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            // Update global answer
            ans = max(ans, maxProd);
        }

        return ans;
    }
};