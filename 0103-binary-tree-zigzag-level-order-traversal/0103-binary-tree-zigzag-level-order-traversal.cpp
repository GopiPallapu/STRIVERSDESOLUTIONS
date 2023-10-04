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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         // step 1 
	    if(root == NULL)return {} ;
	    vector<vector<int>> answer ;
	    queue<TreeNode*> q ;
	    q.push(root) ;
	    int index =0 ;
	    // step 2 
	    while(q.size() > 0)
	    {
	        index ++ ;
	       int size = q.size() ;
	       vector<int> level ;
	       for(int i =0 ;i< size ; i++)
	       {
	           TreeNode* node  = q.front() ;
	           level.push_back(node->val) ;
	           q.pop() ;
	           if(node->left != NULL)
	                q.push(node->left) ;
	           if(node->right != NULL)
	                q.push(node->right) ;
	       }
	       if(index % 2 ==0)
	       {
	           reverse(level.begin() , level.end());
	       }
	       answer.push_back(level);
	    }
	    return answer ;
    }
};