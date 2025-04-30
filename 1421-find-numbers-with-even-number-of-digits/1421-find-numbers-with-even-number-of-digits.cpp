class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int x:nums)
            count+=to_string(x).length()%2==0;
            
        return count;
    }
};