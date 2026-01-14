// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         //O(N^3) - Brute Force -> 3 loops -> gives tle
// vector<vector<int>> ans;
// set<vector<int>> st;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 for(int k=j+1;k<nums.size();k++){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int> vec={nums[i],nums[j],nums[k]};
//                         sort(vec.begin(),vec.end());
//                         st.insert(vec);
//                     }
//                 }
//             }
//         }

//         for(auto v:st){
//             ans.push_back(v);
//         }
// return ans;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> st;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             unordered_set<int> seen;

//             for (int j = i + 1; j < n; j++) {
//                 int third = -(nums[i] + nums[j]);

//                 if (seen.count(third)) {
//                     vector<int> triplet = {nums[i], nums[j], third};
//                     sort(triplet.begin(), triplet.end());
//                     st.insert(triplet);
//                 }
//                 seen.insert(nums[j]);
//             }
//         }
//         return vector<vector<int>>(st.begin(), st.end());
//     }
// };



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    // skip duplicates
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return ans;
    }
};