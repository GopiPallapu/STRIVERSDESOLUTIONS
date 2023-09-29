/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>answer ;
		if(root == NULL)
		{
		    return {};
		}
		queue<Node*> q ;
		q.push(root) ;
		while(q.size() > 0)
		{
		    int currentSize = q.size() ;
		    vector<int> level ;
		    for(int i =0 ;i < currentSize ; i++)
		    {
		        level.push_back(q.front()->val) ;
		        int childernCount = q.front()->children.size() ;
		        for(int j =0 ;j< childernCount ; j++)
		        {
		            q.push(q.front()->children[j]);
		        }
		        q.pop();
		    }
		    answer.push_back(level);
		}
		return answer ;
    }
};