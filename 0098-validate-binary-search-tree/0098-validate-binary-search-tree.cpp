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
    bool isValid(TreeNode* & root , long start , long end)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->val >= start && root->val <= end)
        {
            bool leftSubT = isValid(root->left , start  ,(long)root->val-1l);
            bool rightSubT = isValid(root->right , (long)root->val+1l , end);
            return (leftSubT && rightSubT) ;
        }
        else
        {
            return false;
        }
    }
	bool isValidBST(TreeNode* & root) {
		return isValid(root , INT_MIN , INT_MAX);
	}
};