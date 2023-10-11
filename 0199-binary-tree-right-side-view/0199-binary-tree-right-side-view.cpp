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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer ;
        queue<TreeNode*> q ;
        if(root == NULL)
            return answer ;
        q.push(root) ;
        while(q.size() > 0)
        {
            int size = q.size() ;
            int val =0 ;
            for(int i =0 ;i < size ; i++)
            {
                auto node = q.front() ;
                q.pop() ;
                val = node->val ;
                if(node->left != NULL)
                {
                    q.push(node->left) ;
                }
                if(node->right != NULL)
                {
                    q.push(node->right) ;
                }
                
            }
            answer.push_back(val) ;
        }
        return answer ;
    }
};