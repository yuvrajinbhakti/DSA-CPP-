class Solution {
public:
    /*method 1 : sorting T.C. - O(N Log N+ M Log M) , S.C. - O(1)
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
    */
    /*method2 : use map T.C. - O(N+M),S.C. - O(N+M)
    bool isAnagram(string s, string t) {
        map<char,int> mpp,mpp2;
        for(int i=0;i<s.size();i++) mpp[s[i]]++;
        for(int i=0;i <t.size();i++){
mpp2[t[i]]++;
        }
        return mpp==mpp2;
    }
    */
    /* method 2 better version : use 1 map , T.C. - O(N+M),S.C. - O(N) 
     bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;

        for(int i=0;i<s.size();i++) mpp[s[i]]++;
        for(int i=0;i <t.size();i++){
mpp[t[i]]--;
        }
        for(auto it:mpp){
            if(it.second!=0)return false;
        }
        return true;
    }
    */
    //method 3 : using array
        bool isAnagram(string s, string t) {
        int a[26]={0};
            for(auto it:s)    a[it-'a']++;
            for(auto it:t) a[it-'a']--;
            for(auto it:a) if(it!=0)return false;
            return true;
        }
};