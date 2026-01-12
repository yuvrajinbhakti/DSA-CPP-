// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> ans;
//         int size=nums.size();
//         for(int i=0;i<size;i++){
//             int currProd=1;
//             for(int j=0;j<size;j++){
//                 if(j!=i){
//                     currProd=currProd*nums[j];
//                 }
//             }
//             ans.push_back(currProd);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int preProd=1,suffProd=1,n=nums.size();
      vector<int> prefixProd(n,1),suffixProd(n,1);
      for(int i=1;i<n;i++){
         preProd=preProd*nums[i-1];
        prefixProd[i]=preProd;
      }
      for(int i=n-2;i>=0;i--){
        suffProd = suffProd*nums[i+1];
        suffixProd[i]=suffProd;
      }
      vector<int> ans(n); 
      for(int i=0;i<n;i++){
        ans[i]=prefixProd[i]*suffixProd[i];
      }
      return ans;
    }
};