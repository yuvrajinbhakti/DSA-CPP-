class Solution {
private:
    struct SubtreeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int maxSum = 0; // Stores the maximum sum of any BST subtree

    SubtreeInfo helper(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0}; // Empty subtree is a BST

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if current subtree is a BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return {true, min(root->val, left.minVal), max(root->val, right.maxVal), currSum};
        }

        return {false, 0, 0, 0}; // If not a BST, return invalid values
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
