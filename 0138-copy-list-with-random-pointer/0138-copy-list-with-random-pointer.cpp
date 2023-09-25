/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
    This can be solved using maps and ietartive solution
    basic idea is make a new list from head -> new head -> head->next -> newhead->next etc....
    TC => O(n)
    SC => O(1)
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return head ;
        unordered_map <Node* , Node*> mp ;
        Node* temp = head ;
        while(temp != NULL)
        {
            Node* newNode =  new Node(temp->val) ;
            mp[temp] = newNode ;
            temp = temp->next ;
        }
        temp= head;
        while(temp != NULL)
        {
            mp[temp]->next = mp[temp->next] ;
            mp[temp]->random = mp[temp->random] ;
            temp = temp->next ;
        }
        return mp[head] ; 
    }
};