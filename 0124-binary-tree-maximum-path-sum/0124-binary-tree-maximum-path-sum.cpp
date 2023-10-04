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
   int helper(TreeNode* root , int& answer)
   {
       if(root == NULL)
            return 0;
        int leftH = max(0 , helper(root->left , answer)); // left max if no child or single child return 0
        int rightH = max(0 ,helper(root->right ,answer));// right max if no child or single child return 0
        answer = max(answer , leftH+rightH+root->val); // for current node add left sum and rightSum 
        return max(leftH,rightH)+root->val; // backtracking return max of left and right along with current node
   }
    int maxPathSum(TreeNode* root) {
       int answer =INT_MIN ;
       helper(root , answer);
       return answer ;
    }
};