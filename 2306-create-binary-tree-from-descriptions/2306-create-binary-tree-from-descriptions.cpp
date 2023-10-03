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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int,TreeNode*> created ;
        unordered_map<int,bool>isParent ;
        for(int i =0 ;i < n ; i++)
        {
            TreeNode *parent , *child ;
             // check for parent
            if(created.find(descriptions[i][0]) == created.end())
            {
                parent = new TreeNode(descriptions[i][0]);
                created[descriptions[i][0]] =parent ;
            }
            else
                parent = created[descriptions[i][0]];
            // check for child
            if(created.find(descriptions[i][1]) == created.end())
            {
                child = new TreeNode(descriptions[i][1]);
                created[descriptions[i][1]] =child ;
            }
            else
                child = created[descriptions[i][1]];
            if(descriptions[i][2]==1)
            {
                parent->left = child ;
            }
            else
                parent->right =child ;
            isParent[descriptions[i][1]] = true;
        }
        for(int i =0 ;i < n ; i++)
        {
            if(isParent.find(descriptions[i][0]) == isParent.end())
                return created[descriptions[i][0]];
        }
        return NULL;
    }
};