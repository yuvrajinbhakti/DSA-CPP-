class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i=0;i<nums.size();i++){
            ans+=nums[i][i]=='0' ? '1' : '0';
            //ans+=to_string(1-nums[i][j]-'0');     //alternate
        }
        return ans;
    }
};