// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//     }
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCnt=0,oneCnt=0,twoCnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
               zeroCnt++;
            }
            else if(nums[i]==1){
oneCnt++;
            }
            else{
                twoCnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(zeroCnt){
                nums[i]=0;
                zeroCnt--;
            }
            else if(oneCnt){
                nums[i]=1;
                oneCnt--;
            }
            else nums[i]=2;
        }
    }
};