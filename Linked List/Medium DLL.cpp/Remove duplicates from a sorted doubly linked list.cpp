struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
       Node* temp=head;
       while(temp!=NULL&&temp->next!=NULL)
       {
           Node* nextNode=temp->next;
           while(nextNode!=NULL&&nextNode->data==temp->data)
           {
               Node* dup=nextNode;
               nextNode=nextNode->next;
               free(dup);
           }
           temp->next=nextNode;
           if(nextNode!=NULL)
                nextNode->prev=temp;
           temp=temp->next;
        
       }
       return head;
    }
};