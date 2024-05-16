class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node* temp = new Node(x);
       temp->next=head;
       return temp;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
        Node* ins = new Node(x);
        if (head == NULL)
        return ins;
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ins;
        return head;
    }
};