/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
    using two pointer approach we can find loop, then start from head and loop pointer iterate in 1x speed
    find intersection of both .
    that will be the starting point of loop
    TC => O(n * md) = m - length of loop 
    SC => O(1)
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow )break;
        }
        if(fast == NULL ||fast->next == NULL)return NULL;
        ListNode* ptr1 = head , *ptr2 = slow;
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    
    }
};