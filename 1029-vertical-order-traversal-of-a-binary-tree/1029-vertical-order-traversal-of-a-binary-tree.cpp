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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> answer ;
		map<int, map<int,multiset<int>>> mp ;
		queue<pair<TreeNode* , pair<int,int>>> q ;
		q.push({root , {0,0}});
		while(q.size() >0)
		{
		    auto node = q.front() ;
		    q.pop() ;
		    TreeNode* n = node.first ;
		    int x = node.second.first ;
		    int y = node.second.second ;
		    mp[x][y].insert(n->val) ;
		    if(n->left != NULL)
		    {
		        q.push({n->left , {x-1 , y+1}});
		    }
		    if(n->right != NULL)
		    {
		        q.push({n->right , {x+1 , y+1}});
		    }
		}
	    for(auto nodes : mp)
	    {
	        vector<int> elements ;
	        for(auto q : nodes.second)
	        {
	             elements.insert(elements.end(), q.second.begin(), q.second.end());
	        }
	        answer.push_back(elements);
	    }
	    return answer;
    }
};