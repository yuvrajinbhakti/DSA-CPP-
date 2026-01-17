// class Solution {
// public:
//     int findOnesinNumber(int x){
//     int cnt=0;
//     while(x>0){
//         if(x%2==1)cnt++;
//         x=x/2;
//     }
//     return cnt;
//     }
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         for(int i=0;i<=n;i++){
//             int currOnesCnt= findOnesinNumber(i);
//             ans.push_back(currOnesCnt);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector <int> countBits(int num) {
        vector<int> res(num);
        res.push_back(0);  // for num = 0
        if (num == 0) return res;
        
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0) 
                res[i] = res[i / 2];
            else
                res[i] = res[i - 1] + 1;
        }
        return res;
    }
};