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
    int find(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) return i;
        }
        return -1;
    }

    TreeNode* tree(vector<int>& postorder, vector<int>& inorder, int instart, int inend, int &index) {
        if (instart > inend) return nullptr;

        TreeNode* root = new TreeNode(postorder[index]);
        int pos = find(inorder, postorder[index], instart, inend);
        index--;  // move to previous postorder element

        // build right before left (postorder = left, right, root)
        root->right = tree(postorder, inorder, pos + 1, inend, index);
        root->left  = tree(postorder, inorder, instart, pos - 1, index);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int index = n - 1;
        return tree(postorder, inorder, 0, n - 1, index);
    }
};
