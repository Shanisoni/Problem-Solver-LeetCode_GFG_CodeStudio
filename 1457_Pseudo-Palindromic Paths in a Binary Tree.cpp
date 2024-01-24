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
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        // Start counting pseudo-palindromic paths from the root
        return countPaths(root, 0);
    }

private:
    int countPaths(TreeNode* node, int pathDigits) {
        // Check if the current node is empty
        if (!node) {
            return 0;
        }

        // Update the count based on the current digit of the path
        pathDigits ^= (1 << node->val);

        // If it's a leaf node, check if the path is pseudo-palindromic
        if (!node->left && !node->right) {
            // Check if only one digit is set in pathDigits
            return (pathDigits & (pathDigits - 1)) == 0;
        }

        // Recursively count paths for the left and right subtrees
        int leftPaths = countPaths(node->left, pathDigits);
        int rightPaths = countPaths(node->right, pathDigits);

        // Sum up the paths from both subtrees
        return leftPaths + rightPaths;
    }
    
};