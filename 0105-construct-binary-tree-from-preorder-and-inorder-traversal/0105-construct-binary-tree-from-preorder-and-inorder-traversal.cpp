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
    unordered_map<int,int> mp;
     int index =0;
    TreeNode* helper(vector<int>& preorder , int start , int end )
    {
        if(start > end)
        {
            return NULL;
        }
        TreeNode* rootnode = new TreeNode(preorder[index]);
        index++;
        if(start == end)
        {
            return rootnode;
        }
        int indexInInorder = mp[rootnode->val];
        rootnode->left = helper(preorder , start , indexInInorder-1 );
        rootnode->right = helper(preorder  , indexInInorder+1 , end );
        return rootnode;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int n = inorder.size();
	    for(int i =0 ;i < inorder.size() ; i++)
	    {
	        mp[inorder[i]] = i;
	    }
	    return helper(preorder , 0 , n-1);
    }
};