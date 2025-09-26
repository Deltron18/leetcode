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
    TreeNode* bst(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = bst(nums, start, mid - 1);
        root->right = bst(nums, mid + 1, end);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size() - 1);
    }
};

// class Solution {

// void bst(vector<int> nums, int start,int end,vector<int>&ans)
// {
//     if(start>end)
//     return;

//     int mid=start+(end-start)/2;
//     ans.push_back(nums[mid]);
//     bst(nums,start,mid-1,ans);
//     bst(nums,mid+1,end,ans);
// }

// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         vector<int>ans;
//         int start=0;
//         int end=nums.size()-1;
//         bst(nums,start,end,ans);
//         return ans;
//     }
// };