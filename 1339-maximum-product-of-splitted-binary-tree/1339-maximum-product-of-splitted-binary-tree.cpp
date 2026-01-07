/**
 * Definition for a binary tree node.
 * Each node has:
 *  - an integer value (val)
 *  - a pointer to left child
 *  - a pointer to right child
 */

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};


class Solution {
public:
    long long res = 0;   // Stores the maximum product found
    long long total = 0; // Stores the sum of all nodes in the tree
    long long sub;       // Stores the sum of a subtree

    int maxProduct(TreeNode* root) {

        // First call to s(root): computes total sum of the tree
        // Second call to s(root): computes max product using subtree sums
        total = s(root), s(root);

        // Return result modulo 1e9+7 as required by the problem
        return res % (int)(1e9 + 7);
    }

    // Helper function to calculate subtree sums
    int s(TreeNode* root) {

        // Base case: empty node contributes 0
        if (!root) return 0;

        // Compute sum of current subtree:
        // node value + left subtree sum + right subtree sum
        sub = root->val + s(root->left) + s(root->right);

        // Try splitting the tree at this node:
        // one part = sub
        // other part = total - sub
        // update max product
        res = max(res, sub * (total - sub));

        // Return subtree sum to parent
        return sub;
    }
};

*/


class Solution {
public:
    long long res = 0;                 // Stores maximum product
    vector<long long> subtreeSums;     // Stores sum of every subtree

    int maxProduct(TreeNode* root) {

        // Step 1: Run DFS once and store all subtree sums
        long long total = dfs(root);

        // Step 2: Try splitting the tree at every subtree
        for (long long sub : subtreeSums) {
            // product = subtree sum × remaining tree sum
            res = max(res, sub * (total - sub));
        }

        // Step 3: Return result modulo 1e9+7
        return res % (int)(1e9 + 7);
    }

    long long dfs(TreeNode* root) {

        // Base case: empty node contributes 0
        if (!root) return 0;

        // Compute subtree sum using postorder traversal
        long long sub =
            root->val +
            dfs(root->left) +
            dfs(root->right);

        // Store this subtree sum for later product calculation
        subtreeSums.push_back(sub);

        // Return subtree sum to parent
        return sub;
    }
};
