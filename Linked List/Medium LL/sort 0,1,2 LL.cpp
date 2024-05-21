//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
      Node* zh=new Node(-1);
      Node* oh=new Node(-1);
      Node* th=new Node(-1);
      
      Node* z=zh;
      Node* o=oh;
      Node* t=th;
      Node* temp = head;
      while(temp!=NULL)
      {
          if(temp->data==0)
          {
              z->next=temp;
              z=z->next;
          }
           if(temp->data==1)
          {
              o->next=temp;
              o=o->next;
          }
           else
          {
              t->next=temp;
              t=t->next;
          }
          temp=temp->next;
      }
      z->next=(oh->next)?(oh->next):(th->next);
      o->next=th->next;
      t->next=NULL;
      
      Node* newHead=zh->next;
      delete zh;
      delete oh;
      delete th;
      return newHead;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends