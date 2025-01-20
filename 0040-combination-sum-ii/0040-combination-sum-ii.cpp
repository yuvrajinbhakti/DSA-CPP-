// class Solution {
// public:

//     void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
//   if (target == 0) {
//     ans.push_back(ds);
//     return;
//   }
//   for (int i = ind; i < arr.size(); i++) {
//     if (i > ind && arr[i] == arr[i - 1]) continue;
//     if (arr[i] > target) break;
//     ds.push_back(arr[i]);
//     findCombination(i + 1, target - arr[i], arr, ans, ds);
//     ds.pop_back();
//   }
// }
// vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
//   sort(candidates.begin(), candidates.end());
//   vector < vector < int >> ans;
//   vector < int > ds;
//   findCombination(0, target, candidates, ans, ds);
//   return ans;
// }
// };


// class Solution {
// private:
//     void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& v, int currSum, int index) {
//         if (currSum == target) {
//             ans.push_back(v);  // If the current sum matches the target, store the combination
//             return;
//         }
//         if (currSum > target || index >= candidates.size()) return;  // If the sum exceeds target or we run out of candidates, return
        
//         // Iterate through the candidates and avoid duplicates
//         for (int i = index; i < candidates.size(); ++i) {
//             // Skip duplicates to avoid repeating the same combination
//             if (i > index && candidates[i] == candidates[i - 1]) continue;
            
//             v.push_back(candidates[i]);  // Take the current element
//             helper(candidates, target, ans, v, currSum + candidates[i], i + 1);  // Move to the next element (i + 1)
//             v.pop_back();  // Backtrack to try other combinations
//         }
//     }

// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>> ans;
//         vector<int> v;
//         sort(candidates.begin(), candidates.end());  // Sort the candidates to handle duplicates
//         helper(candidates, target, ans, v, 0, 0);
//         return ans;
//     }
// };


class Solution {
private:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& v, int currSum, int index) {
        if (currSum == target) {
            ans.push_back(v);  // If the current sum matches the target, store the combination
            return;
        }
        if (currSum > target || index >= candidates.size()) return;  // If the sum exceeds target or we run out of candidates, return

        // **Take** the current element and recurse
        v.push_back(candidates[index]);
        helper(candidates, target, ans, v, currSum + candidates[index], index + 1);  // Move to next index (no duplicates allowed at the same level)
        v.pop_back();  // Backtrack

        // **Not Take**: Skip the current element and move to the next one
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;  // Skip duplicates
        }
        helper(candidates, target, ans, v, currSum, index + 1);  // Continue recursion after skipping
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());  // Sort candidates to handle duplicates
        helper(candidates, target, ans, v, 0, 0);
        return ans;
    }
};
