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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer ;
        if(root == NULL)
            return answer ;
        queue<TreeNode*> q ;
        q.push(root);
        while(q.size() > 0)
        {
            int size = q.size() ;
            double sum =0 ;
            for(int i =0 ;i < size ; i++)
            {
                auto node = q.front() ;
                q.pop() ;
                sum += node->val ;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right) ;
            }
            answer.push_back((double)sum/size) ;
        }
        return answer ;
    }
};