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
   
    TreeNode* helper(TreeNode* curr, int val) {
        // Base case: if the current node is NULL or the value matches
        if (curr == NULL || curr->val == val)
            return curr;
        
        // Recurse on left and right subtrees
        TreeNode* leftResult = helper(curr->left, val);
        if (leftResult) return leftResult;

        return helper(curr->right, val); // If not found in the left, check the right
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        return helper(curr,val);
    }
};