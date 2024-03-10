class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        int j=0;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                open++;
            else{
                open--;
                if(open==0)
                {
                    for(int k=j+1;k<i;k++)
                        ans+=s[k];
                    j=i+1;
                }
            }
        }
        return ans;
    }
};
//code studio
int maxDepth(string s) {
	int mDepth=INT_MIN,cDepth=0;
	for(char &ch:s)
	{
		if(ch=='(')
		{
			cDepth++;
			mDepth=max(mDepth,cDepth);
		}
		else if(ch==')')
		cDepth--;
	}
	return mDepth;

}
