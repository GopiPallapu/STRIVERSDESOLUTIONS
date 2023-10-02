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
    bool flag = true ;
   int  helper(TreeNode*  root)
    {
        if(root == NULL)
            return 0;
        int leftH = helper(root->left);
        int rightH =helper(root->right);
        if(abs(leftH - rightH) > 1)
        {
            flag = false;
        }
        return max(leftH,rightH)+1 ;
    }
	bool isBalanced(TreeNode*  root) {
	   helper(root);
       return flag ;
	}
};