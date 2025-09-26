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

    bool bst(TreeNode* root, long long &prev)   // use long long
    {
        if (!root)
            return true;

        bool l = bst(root->left, prev);
        if (!l)
            return false;

        if (root->val <= prev)
            return false;

        prev = root->val;
        return bst(root->right, prev);
    }

public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;  // safe initial value
        return bst(root, prev);
    }
};
