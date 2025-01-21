class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int currMin=prices[0],ans=0;
      for(int i=1;i<prices.size();i++){
        ans=max(prices[i]-currMin,ans);
        if(currMin>prices[i])currMin=prices[i];
      }  
      return ans;
    }
};