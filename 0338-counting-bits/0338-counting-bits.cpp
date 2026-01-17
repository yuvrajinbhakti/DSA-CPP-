class Solution {
public:
    int findOnesinNumber(int x){
    int cnt=0;
    while(x>0){
        if(x%2==1)cnt++;
        x=x/2;
    }
    return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int currOnesCnt= findOnesinNumber(i);
            ans.push_back(currOnesCnt);
        }
        return ans;
    }
};