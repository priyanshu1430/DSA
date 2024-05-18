class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        Node* last=NULL;
        Node* cur=head;
        while(cur!=NULL)
        {
            last=cur->prev;
            cur->prev=cur->next;
            cur->next=last;
            cur=cur->prev;
        }
        head=last->prev;
        return head;
    }
};