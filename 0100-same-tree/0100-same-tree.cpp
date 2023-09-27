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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if(p == NULL && q == NULL)
        {
            return true ;
        }
        if(p == NULL || q == NULL || p->val != q->val)
        {
            return false;
        }
        bool op1 = isSameTree(p->left , q->left) ;
        bool op2 = isSameTree(p->right ,q->right) ;
        return op1 && op2 ;
    }
};