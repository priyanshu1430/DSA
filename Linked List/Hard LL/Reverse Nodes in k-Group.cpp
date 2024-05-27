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
    ListNode* getKthNode(ListNode* temp, int k)
    {
        k -= 1; 
        while(temp != NULL && k > 0)
        {
            k--; 
            temp = temp -> next; 
        }
        return temp; 
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    { 
        ListNode* temp = head; 
        ListNode* prevLast = NULL; 
        while(temp != NULL){
            ListNode* kThNode = getKthNode(temp, k); 
            if(kThNode == NULL)
            {
                if(prevLast)
                {
                    prevLast -> next = temp; 
                }
                break; 
            }
            ListNode* nextNode = kThNode -> next; 
            kThNode -> next = NULL; 
            reverseList(temp); 
            if(temp == head)
            {
                head = kThNode;
            }else
            {
                prevLast -> next = kThNode; 
            }
            prevLast = temp; 
            temp = nextNode; 
        }
        return head; 
        
    }
};