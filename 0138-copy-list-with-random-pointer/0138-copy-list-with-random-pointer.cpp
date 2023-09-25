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
    void copy(Node* head)
    {
        if(head == NULL)
            return ;
        Node* temp = head  , *nxt = head->next;
        while(temp != NULL)
        {
            Node* n = new Node(temp->val) ;
            n->next = nxt ;
            temp->next = n ;
            temp = nxt;
            if(nxt)nxt = nxt->next ;
        }
    }
    void randomM(Node* head)
    {
        Node* temp  = head ;
        while(temp != NULL)
        {
            if(temp->random != NULL)
            {
                temp->next->random = temp->random->next ;
            }
            temp = temp->next->next ;
        }
    }
    Node* detach(Node* head)
    {
        Node* dummy = new Node(-1) ;
        Node* tail  = dummy , *temp = head ;
        while(temp != NULL)
        {
            tail->next = temp->next ;
            tail = tail->next ;
            temp->next = tail->next ;
            temp = temp->next;
        }
        return dummy->next ;
    }
    Node* copyRandomList(Node* head) {
       copy(head) ;
       randomM(head) ;
       return detach(head) ;
    }
};