/*
class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode() {
        }
        
        TreeNode(int data) {
            this->data = data;
        }
        
        TreeNode(int data, TreeNode* left, TreeNode* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};
*/

class Solution {
public:
    int mini = INT_MAX ;
    int previous = -1 ;
    void helper(TreeNode* & root)
    {
        if(root == NULL)
        {
            return ;
        }
        helper(root->left);
        if(previous == -1)
        {
            previous = root->val ;
        }
        else
        {
            mini = min(mini , root->val-previous);
            previous = root->val;
        }
        helper(root->right);
    }
	int minDiffInBST(TreeNode* & root) {
	    if(root == NULL || (root->left == NULL && root->right == NULL))return 0;
		helper(root);
		return mini ;
	}
};