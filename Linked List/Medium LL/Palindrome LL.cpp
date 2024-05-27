class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> listVals;
        while (head) {
            listVals.push_back(head->val);
            head = head->next;
        }
        
        int left = 0, right = listVals.size() - 1;
        while (left < right && listVals[left] == listVals[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
};
//tortoise and hare algo
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
    ListNode* reverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
       if(head==NULL || head->next==NULL)
            return true;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast ->next != NULL&&fast->next->next != NULL )
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newHead);
        return true;
    }
};