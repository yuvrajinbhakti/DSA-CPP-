class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
vector<int> ans;
for(int i=0;i<nums1.size();i++){
    int found=-1, currElement=nums1[i];
  for(int j=0;j<nums2.size();j++){
    if(nums2[j]==currElement){
    for(int k=j;k<nums2.size();k++){
if(nums2[k]>nums2[j]){
    found=nums2[k];
    break;
}
    }
    }

  }
    if(found!=-1){
ans.push_back(found);
    }
    else{
        ans.push_back(-1);
    }
} 

return ans;
    }
};