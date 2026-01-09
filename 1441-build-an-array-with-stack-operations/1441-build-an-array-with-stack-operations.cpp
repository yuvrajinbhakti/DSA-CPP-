class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j = 0;                 // pointer to target

        for (int i = 1; i <= n && j < target.size(); i++) {
            ans.push_back("Push"); // must push every streamed number

            if (i == target[j]) {
                // needed number, keep it
                j++;
            } else {
                // not needed, remove it
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};
