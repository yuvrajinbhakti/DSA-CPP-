class Solution {
public:
    // int maximumSum(vector<int>& nums) {
    //      int res = -1, d_n[82] = {}; // 9 * 9
    // for (int n : nums) {
    //     int d = 0;
    //     for (int nn = n; nn; nn /= 10)
    //         d += nn % 10;
    //     if (d_n[d])
    //         res = max(res, d_n[d] + n);
    //     d_n[d] = max(d_n[d], n);
    // }
    // return res;
    // }
    int maximumSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> v;
    int ans=-1;
    vector<pair<int,int>> p;
    for( int i=0;i<n ;i++){ 
        int a=0, sum=0;
        a=nums[i]; 
         while (a != 0) {
            sum = sum + a % 10;
             a = a / 10;
        }
       
        v.push_back(sum);
    }
    for(int i=0 ;i<n;i++){
        p.push_back(make_pair(v[i], nums[i]));
    }
    sort(p.begin(),p.end());
      
         for(int i=1;i<n ;i++){
             if(p[i].first == p[i-1].first){
                 ans=max(ans,p[i].second+p[i-1].second);
             }
         }
    return ans;
}
};