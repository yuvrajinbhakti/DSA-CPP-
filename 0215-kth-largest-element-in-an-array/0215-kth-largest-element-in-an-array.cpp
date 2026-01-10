
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


//Time: O(n + k log n)
// Space: O(n)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq(nums.begin(),nums.end());
     
        
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
          // Min-heap to keep only k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);

            // Keep heap size at most k
            if (minHeap.size() > k) {
                minHeap.pop();  // remove smallest among the k+1 elements
            }
        }

        // Top of min-heap is the kth largest element
        return minHeap.top();
    }
};


// | Approach                 | Time             | Space      |
// | ------------------------ | ---------------- | ---------- |
// | Max Heap (your original) | `O(n + k log n)` | `O(n)`     |
// | **Min Heap (optimized)** | **`O(n log k)`** | **`O(k)`** |
// | Quickselect              | `O(n)` avg       | `O(1)`     |
