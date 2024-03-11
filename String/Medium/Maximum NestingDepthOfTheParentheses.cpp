class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxsize=0;
       for(auto c:s)
       {
           if(c=='(')
            st.push(c);
           int n=st.size(); 
           maxsize=max(maxsize,n);
           if(c==')')
            st.pop();
       }
        return maxsize;
    }
};