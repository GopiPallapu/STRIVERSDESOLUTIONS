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
    void helper(TreeNode* & root ,int currentDepth , int depth, int val)
    {
        if(root == NULL)
            return  ;
        if(currentDepth == depth-1)
        {
            TreeNode* preL =root->left ;
            TreeNode* preR = root->right ;
            TreeNode* newL = new TreeNode(val);
            TreeNode* newR = new TreeNode(val);
            root->left =newL ;
            root->right = newR;
            root->left->left = preL;
            root->right->right = preR ;
            return  ;
        }
        helper(root->left , currentDepth+1 , depth, val);
        helper(root->right , currentDepth+1 , depth, val);
    }
	TreeNode*  addOneRow(TreeNode* & root, int val, int depth) {
	    if(root == NULL)  
	        return NULL;
		if(depth == 1)
		{
		    TreeNode* newN = new TreeNode(val);
		    newN->left = root ;
		    return newN;
		}
		helper(root , 1 ,depth ,val);
		return root;
	}
};