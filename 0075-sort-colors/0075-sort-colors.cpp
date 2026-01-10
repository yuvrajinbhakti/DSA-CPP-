// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//     }
// };

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int zeroCnt=0,oneCnt=0,twoCnt=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0){
//                zeroCnt++;
//             }
//             else if(nums[i]==1){
// oneCnt++;
//             }
//             else{
//                 twoCnt++;
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             if(zeroCnt){
//                 nums[i]=0;
//                 zeroCnt--;
//             }
//             else if(oneCnt){
//                 nums[i]=1;
//                 oneCnt--;
//             }
//             else nums[i]=2;
//         }
//     }
// };

// Dutch National Flag algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        //0 to mid-1
        //mid
        // mid+1 to high
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};