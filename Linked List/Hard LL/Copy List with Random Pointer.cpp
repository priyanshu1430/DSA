/*
// Definition for a Node.
class Node {
public: 
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopy(Node* head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* nextele=temp->next;
            Node* copyNode=new Node(temp->val);
            copyNode->next=nextele;
            temp->next=copyNode;
            temp=nextele;
        }
    }
    void coonectRndPtr(Node* head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* copyNode=temp->next;
            if(temp->random)
                copyNode->random=temp->random->next;
            else
                copyNode->random=NULL;
            temp=temp->next->next;
        }
    } 
    Node* getCpyLL(Node* head)
    {
        Node* temp=head;
        Node* dummy = new Node(-1);
        Node* res= dummy;
        while(temp!=NULL)
        {
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
       insertCopy(head);
       coonectRndPtr(head);
       return getCpyLL(head);
    }
};