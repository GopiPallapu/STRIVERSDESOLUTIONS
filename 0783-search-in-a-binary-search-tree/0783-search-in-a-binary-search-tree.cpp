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
    TreeNode* isFound(TreeNode*  root, int val)
    {
        if(root == NULL)
            return NULL ;
        if(root->val == val)
            return root ;
        if(root->val < val)
        {
            return isFound(root->right , val);
        }
        else
        {
            return isFound(root->left , val);
        }
        return root;
    }
	TreeNode* searchBST(TreeNode*  root, int val) {
	    return isFound(root , val);
	}
};