class Solution {
public:
    // int hammingWeight(int n) {
    //     int cnt=0;
    //     while(n>0){
    //         if(n%2==1){
    //         cnt++;
    //         } 
    //         // n=n/2;
    //         n=n>>1;
    //     }
    //     return cnt;
    // }
    int hammingWeight(uint32_t n) {
    int count = 0;
    
    while (n) {
        n &= (n - 1);
        count++;
    }
    
    return count;
}
};