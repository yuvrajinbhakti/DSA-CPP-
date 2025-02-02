class Solution {
public:
    int findMax(int n,int s,int e,int w,int k){
        int ans=0;
        int dupl=k;
        int dn=n,ds=s,de=e,dw=w;
        if(n>s){
            int minimum = min(s,k);
            n+=minimum;
            s-=minimum;
            k-=minimum;
        }else{
            int minimum = min(n,k);
            s+=minimum;
            n-=minimum;
            k-=minimum;
        }
        if(w>e){
            int minimum = min(e,k);
            w+=minimum;
            e-=minimum;
            k-=minimum;
        }
        else{
            int minimum = min(w,k);
            e+=minimum;
            w-=minimum;
            k-=minimum;
        }
        ans=max(ans,abs(n-s)+abs(w-e));
        k=dupl,n=dn,e=de,s=ds,w=dw;
        if(w>e){
            int minimum = min(e,k);
            w+=minimum;
            e-=minimum;
            k-=minimum;
        }
        else{
            int minimum = min(w,k);
            e+=minimum;
            w-=minimum;
            k-=minimum;
        }
        if(n>s){
            int minimum = min(s,k);
            n+=minimum;
            s-=minimum;
            k-=minimum;
        }else{
            int minimum = min(n,k);
            s+=minimum;
            n-=minimum;
            k-=minimum;
        }
        ans=max(ans,abs(n-s)+abs(w-e));
        return ans;
    }
    int maxDistance(string dir, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=0,s=0,e=0,w=0;
        int ans=0;
        for(auto &i : dir){
            n+=i=='N';
            s+=i=='S';
            e+=i=='E';
            w+=i=='W';
            // Greedily checking the farthest i can go with the current moves
            ans=max(ans,findMax(n,s,e,w,k));
        }
        
        return ans;
    }
};
// class Solution {
// public:
//   int maxDistance(string s, int k) {
//     int res = 1, hor = 0, ver = 0;
//     for (int i = 0; i < s.size(); ++i) {
//         ver += s[i] == 'N' ? 1 : s[i] == 'S' ? -1 : 0;
//         hor += s[i] == 'W' ? 1 : s[i] == 'E' ? -1 : 0;
//         res = max(res, min(abs(hor) + abs(ver) + 2 * k, i + 1));
//     }
//     return res;
// }
// };