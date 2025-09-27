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

TreeNode* bst(vector<int>& preorder,int &index,int lower,int upper)
{

if((index==preorder.size()) || (preorder[index]<lower) || (preorder[index]>upper))
return NULL;


    TreeNode*root=new TreeNode(preorder[index++]);
    root->left=bst(preorder,index,lower,root->val);
    root->right=bst(preorder,index,root->val,upper);
    return root;
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int lower=INT_MIN;
        int upper=INT_MAX;
        int index=0;
       return bst(preorder,index,lower,upper);
    
    }
};