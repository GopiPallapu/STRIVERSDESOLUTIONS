/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Approach:
    find middle element
    reverse mid + l to last elements
    start with two pointers one form head, second from mid next check val if not not match return false;
    iterate till last then return true and reverse l mid + 1 elements again to convert in into org list
    TC => O(n + n/2 + n/2) -> O(n)
    SC => O(1)
 */
class Solution {
public:
     ListNode* reverse(ListNode*start )
    {
        ListNode* p = NULL , *c = start , *n = start->next;
        while(c!=NULL)
        {
            c->next = p;
            p = c;
            c = n;
            if(n)n = n->next;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head  ,*fast = head , *first =head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        ListNode *second = slow->next;
        while(second != NULL)
        {
            if(first->val != second->val)return false;
            second = second->next;
            first= first->next;
        }
        slow->next = reverse(slow->next);
        return true;
    }
};