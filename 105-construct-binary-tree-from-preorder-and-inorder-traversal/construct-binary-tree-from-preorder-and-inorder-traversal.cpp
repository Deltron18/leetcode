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


    int find(vector<int> inorder,int target,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==target)
            return i;
        }
        return -1;
    }

TreeNode*tree(vector<int> preorder,vector<int> inorder,int instart,int inend,int index)
{
    if(instart>inend)
    return NULL;

    TreeNode*root=new TreeNode(preorder[index]);
    int pos=find(inorder,preorder[index],instart,inend);
    root->left=tree(preorder,inorder,instart,pos-1,index+1);
    root->right=tree(preorder,inorder,pos+1,inend,index+(pos-instart)+1);

    return root;

}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return tree(preorder,inorder,0,n-1,0);
    }
};