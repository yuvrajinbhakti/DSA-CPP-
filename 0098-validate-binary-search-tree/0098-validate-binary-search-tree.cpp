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
// class Solution {
// public:
// bool helper(TreeNode* root, long long mini,long long maxi){
//     if(root==NULL)return true;
//     if(root->val >= maxi || root->val <=mini)return false;
//     bool left=helper(root->left,mini,root->val);
//     bool right=helper(root->right,root->val,maxi);
//     return left && right;
// }
//     bool isValidBST(TreeNode* root) {
//         if(root==NULL || (root->left==NULL && root->right==NULL))return true;
//         return helper(root,LLONG_MIN,LLONG_MAX);
//     }
// };


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};