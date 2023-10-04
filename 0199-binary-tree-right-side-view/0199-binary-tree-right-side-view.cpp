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
    void helper(TreeNode* root ,int level ,vector<int>& answer)
    {
        if(root == NULL)
        {
            return ;
        }
        if(level == answer.size())
            answer.push_back(root->val);
        helper(root->right , level + 1 , answer);
        helper(root->left , level+1 ,answer);
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer ;
        helper(root ,0, answer);
        return answer ;
    }
};