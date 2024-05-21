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
    ListNode* deleteMiddle(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(head==NULL||head->next==NULL)
            return NULL;
         ListNode* slow=head;
         ListNode* fast=head;
         fast=fast->next->next;
         while(fast!=NULL&&fast->next!=NULL)
         {
            slow=slow->next;
            fast=fast->next->next;
         }
          ListNode* del=slow->next;
          slow->next=slow->next->next;
          delete del;
          return head;
    }
};