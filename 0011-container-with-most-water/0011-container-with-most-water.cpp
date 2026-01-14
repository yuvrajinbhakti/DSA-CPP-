class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int ans=0;
        while(left<=right){
            int currLen=min(height[left],height[right]),currWidth=right-left;
            int currArea=currLen*currWidth;
            ans=max(currArea,ans);
            if(height[left]<height[right])left++;
            else right--;
        }
        return ans;
    }
};