class Solution {
public:
    string reverseWords(string s) {
	string result="";
	int n=s.size();
	int i=0,j;
	string s2="";
	while(i<n)
	{
		j=i;
		while(i<n&&s[i]==' ')//counting the last index of space
			i++;
		if(i>=n)
			break;
		 j=i+1;
		while(j<n&&s[j]!=' ')//counting the last index of char
			j++;
		s2=s.substr(i,j-i);
		if(result.size()==0)
			result=s2;
		else
			result=s2+' '+result;
		i=j+1;
	}
	return result;
}

};