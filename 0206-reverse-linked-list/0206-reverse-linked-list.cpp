/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if(head->next == NULL)return head;
        ListNode* revHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return revHead;
    }
    ListNode* reverseList(ListNode* head) {
        // recurrsive approach
        if(head == NULL )return NULL;
        return reverse(head);
        /*
        if(head == NULL || head->next == NULL )return head;
        ListNode *previous = NULL , *current = head , *n = head->next;
        while(current != NULL)
        {
            current->next =previous;
            previous =current ;
            current  = n;
            if(n)n = n->next;
        }
        return previous;*/
    }
};