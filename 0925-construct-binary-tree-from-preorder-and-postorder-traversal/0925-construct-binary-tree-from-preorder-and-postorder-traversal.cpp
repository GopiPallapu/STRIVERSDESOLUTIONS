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
    TreeNode* helper(int preS ,int preE , vector<int>& preorder , int posS ,int posE ,vector<int>& postorder)
    {
        if(preS > preE)return NULL;
        TreeNode* root =   new TreeNode(preorder[preS]);
        if(preS == preE)
            return root ;
        int postRoot = posS ;
        for(int i =0 ; i< posE ; i++)
        {
            if(postorder[i] == preorder[preS+1])
            {
                postRoot = i;
                break;
            }
        }
        int postLSt = posS  , postLEnd = postRoot ;
        int postRSt = postRoot+1 , postREnd =posE-1;
        
        int preLSt = preS +1 , preLEnd = preS+1 + (postLEnd- postLSt);
        int preRSt =preLEnd+1 , preREnd = preE ;
        root->left = helper(preLSt , preLEnd , preorder , postLSt , postLEnd , postorder);
        root->right = helper(preRSt , preREnd , preorder , postRSt , postREnd , postorder);
        return root ;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       int n = preorder.size() ;
       return helper(0,n-1 ,preorder , 0 , n-1 , postorder);
    }
};