/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
    this can be solved in two ways.
    recurresive approach : solve small problem and pass remaining problem to recurrsion
    Iterative approach : iterate every k nodes and reverse those
    TC => O(n)
    SC => O(1)/O(n)
 */
class Solution {
public:
    void reverse(ListNode* start , ListNode* end)
    {
        ListNode* previous = NULL , *c = start , *n = start->next;
        while(previous != end)
        {
            c->next = previous ; 
            previous  =c;
            c = n;
            if(n)n = n->next;

        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)return head;
      /*  ListNode* dummy = new ListNode(-1);
        dummy->next  =head;
        ListNode* beforeStart = dummy , *end = head;
        int i =0;
        while(end != NULL)
        {
            i++;
            if(i%k == 0)
            {
                ListNode* start = beforeStart->next;
                ListNode* temp = end->next;
                reverse(start , end);
                beforeStart->next = end;
                start->next = temp;
                beforeStart = start;
                end = temp;
            }
            else
            {
                end  =  end->next;
            }
        }
        return dummy->next;*/
        // recurrsive solution
        ListNode* start = head , *end = head;
        int inc = k-1;
        while(inc--)
        {
            end = end->next;
            if(end == NULL)return head;
        }
        ListNode* newHead = reverseKGroup(end->next , k);
        reverse(start,end);
        start->next = newHead;
        return end;
    }
};