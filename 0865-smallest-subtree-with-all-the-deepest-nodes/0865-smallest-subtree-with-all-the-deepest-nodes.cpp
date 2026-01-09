class Solution {
public:
    // Returns {deepest depth in subtree, subtree root containing all deepest nodes}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        // Base case: empty tree has depth 0 and no subtree
        if (!root) {
            return {0, nullptr};
        }

        // Recursively process left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If left subtree is deeper, propagate its result
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // If right subtree is deeper, propagate its result
        if (right.first > left.first) {
            return {right.first + 1, right.second};
        }

        // If both depths are equal, current node is the LCA of deepest nodes
        return {left.first + 1, root};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
