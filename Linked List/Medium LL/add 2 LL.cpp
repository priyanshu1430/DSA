class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dummy=new ListNode(-1); 
        ListNode*  cur=dummy;
        int total=0;
        int carry=0;
        while(t1||t2||carry)
        {
            total=carry;
            if(t1)
            {
                total+=t1->val;
                t1=t1->next;
            }
             if(t2) {
                total+=t2->val;
                t2=t2->next;
            }
            ListNode* newNode=new ListNode(total%10);
            carry=total/10;
            cur->next=newNode;
            cur=cur->next;             
        }
    return dummy->next;

    }
};