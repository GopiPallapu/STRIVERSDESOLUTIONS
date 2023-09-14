/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
    using two pointers , iterate both pointers, and assign pointer 1 to list 2 if it reahces to end
    same for list2 as well
    if lists are intersected , then they met at some point , else both will meet at end
    TC => O(n+n)
    SC => O(1)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *start = headA , *end = headB;
        while(start != end)
        {
            if(start == NULL)
              start = headB;
            else 
              start = start->next;
            if(end == NULL)
              end = headA;
            else
              end = end->next;
        }
        return start;
    }
};