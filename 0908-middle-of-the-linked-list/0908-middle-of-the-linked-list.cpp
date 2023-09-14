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
    /*
        Approach :
        using two pointers slow and fast we find out middle element
        TC => O(n)
        SC => O(1)
    */
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode* slow = head , *fast = head;
        while(fast !=NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};