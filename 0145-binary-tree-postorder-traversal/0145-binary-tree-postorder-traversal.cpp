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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> answers ;
       stack<TreeNode*> st1 ,st2 ;
       if(root == NULL)
        return answers ;
       st1.push(root);
       while(st1.size() > 0)
       {
           st2.push(st1.top());
           auto node = st1.top();
           st1.pop();
           if(node->left != NULL)
            st1.push(node->left);
           if(node->right != NULL)
            st1.push(node->right);
       }
       while(st2.size() > 0)
       {
           answers.push_back(st2.top()->val);
           st2.pop();
       }
       return answers;
    }
};