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
    map<int,int> mp ;
    int index =0 ;
    TreeNode* help(vector<int>& preorder , int start , int end)
    {
        if(start > end)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++ ;
        if(start == end)
        {
            return root ;
        }
        int indexINInOrder = mp[root->val] ;
        root->left = help(preorder  , start , indexINInOrder-1) ;
        root->right = help(preorder , indexINInOrder+1 ,end) ;
        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i =0 ; i< inorder.size() ; i++)
        {
            mp[inorder[i]] = i ;
        }
        return help(preorder , 0 , preorder.size()-1 ) ;
    }
};