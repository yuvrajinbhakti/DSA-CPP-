/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool helper(TreeNode* root, int k,map<int,int> &mpp){
if(root==NULL)return false;
if(mpp.find(k-root->val)!=mpp.end())return true;
mpp[root->val]++;
return helper(root->left,k,mpp) || helper(root->right,k,mpp);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        //do dfs and store elements in map ,also check if target-element exist
        map<int,int > mpp;
        return helper(root,k,mpp); 
    }
};