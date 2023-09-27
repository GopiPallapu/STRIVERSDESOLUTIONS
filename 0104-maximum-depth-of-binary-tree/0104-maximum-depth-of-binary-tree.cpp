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
    int helper(TreeNode* root)
    {
        // base case
        if(root == NULL)
        {
            return 0;
        }
        int leftH = helper(root->left);
        int rightH  =helper(root->right) ;
        return max(leftH , rightH)+1 ;
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};