/*
class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode() {
        }
        
        TreeNode(int val) {
            this->val = val;
        }
        
        TreeNode(int val, TreeNode* left, TreeNode* right) {
            this->val = val;
            this->left = left;
            this->right = right;
        }
};
*/

class Solution {
public:
    TreeNode* helper(vector<int>& nums ,int start ,int end)
    {
        if(start > end)
        {
            return NULL;
        }
        int mid = (start+end)/2 ;
        TreeNode* root  = new TreeNode(nums[mid]) ;
        root->left = helper(nums , start ,mid-1);
        root->right = helper(nums,mid+1 , end);
        return root ;
    }
	TreeNode*  sortedArrayToBST(vector<int>& nums) {
		return helper(nums , 0 , nums.size()-1);
	}
};