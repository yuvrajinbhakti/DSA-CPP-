class Solution {
public:
    char kthCharacter(int k) {
        string sb="a";
        while(sb.length()<k){
            int size=sb.length();
            for(int i=0;i<size;i++){
                char nextChar='a'+((sb[i]-'a'+1)%26);
                sb+=nextChar;
            }
        }
        return sb[k-1];
    }
};

/*
  char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
*/
