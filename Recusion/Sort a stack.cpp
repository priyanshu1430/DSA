/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert_crt_pos(int x,stack<int> &s)
{
    if(s.size()==0||s.top()<x)
        s.push(x);
    else
    {
        int a=s.top();
        s.pop();
        insert_crt_pos(x,s);
        s.push(a);
    }
}
void reverse(stack<int> &s)
{
    if(s.size()>0)
    {
        int x=s.top();
        s.pop();
        reverse(s);
        insert_crt_pos(x,s);
    }
}
void SortedStack :: sort()
{
   reverse(s);
}