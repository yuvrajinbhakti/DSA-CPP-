// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         return nums[0];
//     }
// };

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n=nums.size(),low=0,high=n-1;
//         int ans=INT_MAX;
//         while(low<=high){
//             if(nums[low]<=nums[high]){
//                 ans=min(ans,nums[low]);
//                 break;
//             }

//             int mid=(high+low)/2;
//             ans=min(ans,nums[mid]);
//             if(nums[low]<=nums[mid]){   //left sorted
//             low=mid+1;
//             }
//             else {  //right sorted
//             high=mid-1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // minimum is in right half
                low = mid + 1;
            } else {
                // minimum is in left half (including mid)
                high = mid;
            }
        }
        return nums[low];
    }
};
