//T.C. = o(n log n)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         return nums[nums.size()-k];
//     }
// };

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;
//         // if manually pushing then it will again be t.c. of N Log N as log N for inserting N times
//         for(int i=0;i<nums.size();i++){
//             pq.push(nums[i]);
//         }
//         while(k>1){
//             pq.pop();
//             k=k-1;
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
     
        
        while(k>1){
            pq.pop();
            k=k-1;
        }
        return pq.top();
    }
};