// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> ans;
//         int size=nums.size();
//         vector<int> freq(size+1);
//         for(int i=0;i<size;i++){
//             freq[nums[i]]++;
//         }
//         for(int i=1;i<freq.size();i++){
//             if(freq[i]==0)ans.push_back(i);
//         }
//         return ans;
//     }
// };

//if inplace allowed
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        // Mark visited numbers
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        // Collect indices that were never marked
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};

/*
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> arr(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(arr.find(i) == arr.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
*/
