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
        Node* temp  =head , *n = head->next;
        while(temp != NULL)
        {
            Node* node = new Node(temp->val);
            node->next = n;
            temp->next = node;
            temp  = n;
            if(n)n = n->next;
        }
    }
    void random(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
                if(temp->random != NULL)
                {
                    temp->next->random = temp->random->next;
                }
                temp  =temp->next->next;
        }
    }
    Node* detach(Node* head)
    {
        Node* dummy = new Node(-1);
        Node* tail = dummy  ,*temp = head;
        while(temp != NULL)
        {
                tail->next = temp->next;
                tail = tail->next;
                temp->next = tail->next;
                temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL)return head;
       /* unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(temp != NULL)
        {
            Node* newNode =  new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL)
        {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];*/
        copy(head);
        random(head);
        return detach(head);
    }
};