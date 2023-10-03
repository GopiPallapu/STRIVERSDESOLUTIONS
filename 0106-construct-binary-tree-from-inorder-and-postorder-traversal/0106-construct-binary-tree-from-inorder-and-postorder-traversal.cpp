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
    TreeNode* helper(vector<int>& postOrder , int start , int end )
    {
        if(start > end)
        {
            return NULL;
        }
        TreeNode* rootnode = new TreeNode(postOrder[index]);
        index--;
        if(start == end)
        {
            return rootnode;
        }
        int indexInInorder = mp[rootnode->val];
        rootnode->right = helper(postOrder  , indexInInorder+1 , end );
        rootnode->left = helper(postOrder , start , indexInInorder-1 );
        return rootnode;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        index =n-1;
	    for(int i =0 ;i < inorder.size() ; i++)
	    {
	        mp[inorder[i]] = i;
	    }
	    return helper(postorder , 0 , n-1);
    }
};