// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         if(nums.size()==1)return false;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1])return true;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//        set<int> st;
//        for(int i=0;i<nums.size();i++){
//         st.insert(nums[i]);
//        }
//        return !(nums.size()==st.size());
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> st;
       for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
       }
       return !(nums.size()==st.size());
    }
};