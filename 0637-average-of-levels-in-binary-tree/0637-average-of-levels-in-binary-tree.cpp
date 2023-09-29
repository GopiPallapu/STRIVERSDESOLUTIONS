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
         if(root == NULL)
            return {} ;
        queue<TreeNode*> q ;
        q.push(root) ;
        vector<double> answer ;
        while(q.size() > 0)
        {
            int currentsize = q.size() ;
            double sum = 0;
            for(int i =0 ;i< currentsize ; i++)
            {
                sum += q.front()->val;
                if(q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            sum = sum/ (double)currentsize ;
            answer.push_back(sum);
        }
        return answer ;
    }
};