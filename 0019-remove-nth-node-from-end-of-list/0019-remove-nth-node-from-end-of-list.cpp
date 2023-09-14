/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
    using two pointers,
    move fast pointer n times, then start slow and fast pointer in 1x speed 
    once fast reaches end , slow will be at n-1 position from end, remove slow of next
    TC => O(n)
    SC => O(1) 
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head,*fast=head;
        while(n--){
            fast=fast->next;
        }
        if(fast==NULL){
            return slow->next;
        
        }
        while(fast->next != NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};