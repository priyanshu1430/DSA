/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
             if(fast == slow)//after collison
             {
                slow=head;//set slow to start
                while(slow!=fast)//again collide is the start point
                {
                    slow=slow->next;//move by one palce
                    fast=fast->next;//move by one place
                }
                return slow;
             }
        }
        return NULL;
    }
};