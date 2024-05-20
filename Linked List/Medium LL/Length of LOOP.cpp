int countNodesinLoop(struct Node *head)
{
        Node *fast = head;
        Node *slow = head;
        int cnt=0;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
             if(fast == slow)//after collison
             {
                fast=fast->next;
                cnt++;
                while(slow!=fast)//again collide is the start point
                {
                    fast=fast->next;//move by one place
                    cnt++;
                }
                return cnt;
             }
        }
        return cnt;
}