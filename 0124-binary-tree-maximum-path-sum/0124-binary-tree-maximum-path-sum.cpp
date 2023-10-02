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
    int maxSum(TreeNode* root , int& answer)
    {
        if(root == NULL)
            return 0 ;
        int leftH = max(0 , maxSum(root->left , answer));
        int rightH = max(0 , maxSum(root->right , answer));
        answer = max(answer , leftH+rightH+root->val);
        return max(leftH , rightH)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int answer =INT_MIN;
        maxSum(root,answer);
        return answer ;
    }
};