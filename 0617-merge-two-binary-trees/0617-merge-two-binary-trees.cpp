/*
class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode() {
            this->left = this->right = NULL;
        }
        
        TreeNode(int data) {
            this->data = data;
            this->left = this->right = NULL;
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
	TreeNode*  mergeTrees(TreeNode* & root1, TreeNode* & root2) {
		if(root1 == NULL || root2 == NULL)
		{
		    if(root1 == NULL)
		        return root2;
		    else
		        return root1;
		}
		root1->val +=root2->val;
		root1->left = mergeTrees(root1->left , root2->left);
		root1->right = mergeTrees(root1->right , root2->right);
		return root1;
	}
};