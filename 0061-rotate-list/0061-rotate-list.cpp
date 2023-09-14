/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
        finding length and start iterating from length to k times and break list and return 
        TC => O(n+k)
        SC => O(1)
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1;
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        while(temp->next != NULL)
        {
            n++;
            temp = temp->next;
        }
        k = k%n;
        k = n-k;
        temp->next = head;
        while(k--)
        {
            temp = temp->next;
        }
        head =temp->next;
        temp->next = NULL;
        return head;
    }
};