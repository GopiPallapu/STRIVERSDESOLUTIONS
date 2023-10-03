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
    void helper(TreeNode*  root , int k , int& answer, int& count)
    {
        if(root == NULL)
        {
            return ;
        }
        helper(root->left  ,k , answer, count);
        count++;
        if(k == count)
            answer = root->val ;
        helper(root->right ,k , answer,count);
    }
	int kthSmallest(TreeNode* & root, int k) {
	    int answer =0;
	    int count =0;
	    helper(root, k , answer , count);
	    return answer ;
	}
};