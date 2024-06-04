class Solution{
public:
    void insertAtBottom(stack<int> &s,int ele)
    {
        if(s.empty())
        {   s.push(ele);
            return;
        }
        int top=s.top();
        s.pop();
        insertAtBottom(s,ele);
        s.push(top);
    }
    void Reverse(stack<int> &s)
    {
        if(s.empty())
            return;
        int top=s.top();
        s.pop();
        Reverse(s);
        insertAtBottom(s,top);
    }
};