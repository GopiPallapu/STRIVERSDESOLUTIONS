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
   int  helper(TreeNode*  root)
    {
        if(root == NULL)
            return 0;
        int leftH = helper(root->left);
        if(leftH == -1)return -1;
        int rightH =helper(root->right);
        if(rightH == -1)return -1;
        if(abs(leftH - rightH) > 1)return -1;
        return max(leftH,rightH)+1 ;
    }
	bool isBalanced(TreeNode*  root) {
	    return helper(root)  != -1;
	}
};