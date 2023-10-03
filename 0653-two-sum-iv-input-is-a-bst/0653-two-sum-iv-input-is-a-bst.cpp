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
    void InOrder(TreeNode* & root ,vector<int>& answer)
    {
        if(root == NULL)
        {
            return ;
        }
        InOrder(root->left , answer);
        answer.push_back(root->val);
        InOrder(root->right ,answer);
    }
    bool findPair(vector<int>& nums , int k)
    {
        int left =0;
        int right = nums.size()-1;
        while(left < right)
        {
            if(nums[left]+nums[right] == k)return true;
            else if(nums[left]+nums[right] > k)right--;
            else
                left++;
        }
        return false;
    }
	bool findTarget(TreeNode* & root, int k) {
		vector<int>In ;
		InOrder(root ,In);
		return findPair(In ,k);
	}
};