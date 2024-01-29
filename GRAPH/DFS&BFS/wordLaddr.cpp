#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
int wordLadder(string begin, string end, vector<string> &dict) 
{
	queue<pair<string,int>> q;
	q.push({begin ,1});
	unordered_set<string> st(dict.begin(),dict.end());
	st.erase(begin);
	while(!q.empty())
	{
		string word=q.front().first;
		int steps=q.front().second;
		q.pop();
    	
		if(word==end)// we return the steps as soon as
			return steps; // the first occurence of targetWord is found.
		for(int i=0;i<word.size();i++)
		{
			char original =word[i];
			for(char ch='a';ch<='z';ch++)
			{
				word[i]=ch;
				if(st.find(word)!=st.end())
				{
					st.erase(word);
					q.push({word,steps+1});
				}
			}
			word[i]=original;
		}
	}
	return -1;
}