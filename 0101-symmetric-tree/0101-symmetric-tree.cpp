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
    bool isSame(TreeNode* root1 , TreeNode* root2)
    {
        // base case
        if(root1 == NULL || root2 == NULL)
        {
            return root1 == root2 ;
        }
        if(root1->val == root2->val)
        {
            bool left = isSame(root1->left , root2->right) ;
            bool  right = isSame(root1->right , root2->left) ;
            return left && right ;
        }
        else
        {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true ;
        return isSame(root->left , root->right);
    }
};