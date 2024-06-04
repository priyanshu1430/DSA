//only add open if open<n
//only add close if close<open
//valid only if open==close==n
class Solution {
public:
    void solve(vector<string>&ans,string temp,int n,int open,int close)
    {
        if(open==n&&close==n)
        {
            ans.push_back(temp);
            return;
        }
        if(open<n)
        {
            temp.push_back('(');
            solve(ans,temp,n,open+1,close);
            temp.pop_back();
        }
        if(close<open)
        {
            temp.push_back(')');
            solve(ans,temp,n,open,close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string> ans;
        string temp;
        solve(ans,temp ,n,open,close);
        return ans;
    }
};