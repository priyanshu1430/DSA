class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};
class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* pre =head;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            Node* temp =new Node(arr[i]);
            pre->next=temp;
            temp->prev=pre;
            pre=temp;
        }
        return head;
    }
};