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
    ListNode* reverseList(ListNode* head) {
        ListNode* back=NULL;
        ListNode* cur=head;
        ListNode* front;
        while(cur!=NULL)
        {
            front=cur->next;
            cur->next=back;
            back=cur;
            cur=front;
        }
        return back;
    }
};
//Recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};