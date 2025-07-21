class Solution {
public:
    string makeFancyString(string s) {
        vector<char> chars(s.begin(),s.end());
        char last=chars[0];
        int cnt=1,pos=1;
        for(int i=1;i<chars.size();++i){
            if(chars[i]!=last){
                last=chars[i];
                cnt=0;
            }
            if(++cnt>2)continue;
            chars[pos++]=chars[i];
        }
        return string(chars.begin(),chars.begin()+pos);
    }
};