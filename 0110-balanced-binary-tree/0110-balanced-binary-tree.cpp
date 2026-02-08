// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     private:
//     int height(TreeNode* node){
//         if(node==NULL)return 0;
//         int leftht=height(node->left);
//         int rightht=height(node->right);
//         return 1+max(leftht,rightht);
//     }

//     bool helper(TreeNode* root){
//         if(root==NULL)return true;
//         int leftHt=height(root->left);
//         int rightHt=height(root->right);
//         if( abs(rightHt-leftHt)>1)return false;
//         return helper(root->left) && helper(root->right);
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         return helper(root);
//     }
// };


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
    int helperDfs(TreeNode* root){
        if(root==NULL)return 0;

        int left=helperDfs(root->left);
        if(left==-1)return -1;

        int right=helperDfs(root->right);
        if(right==-1)return -1;

        if(abs(right-left)>1)return -1;
        
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return helperDfs(root)!=-1;
    }
};

