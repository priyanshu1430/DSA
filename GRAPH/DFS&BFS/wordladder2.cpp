vector<vector<string>> shortestTransitionPaths(string begin, string end, vector<string>& wordPool)
{
    queue<vector<string>> q;
	q.push({begin});
	unordered_set<string> st(wordPool.begin(),wordPool.end());
	vector<string> usedOnLevel;
    usedOnLevel.push_back(begin);
    int level=0;
    vector<vector<string>> ans;
    while(!q.empty())
    {
        vector<string> vec =q.front();
        q.pop();
        if(vec.size()>level)
        {
            level++;            //erase all words that has been used
            for(auto it:usedOnLevel)              //inthe previous levels to transform
                st.erase(it);
            usedOnLevel.clear();
        }
        string word=vec.back();
        if(word==end)
        {
            if(ans.size()==0)   //the first sequence where we reached end
                ans.push_back(vec);
            else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
        }
        for(int i=0;i<word.size();i++)
        {
            char original = word[i];
            for(char c='a';c<='z';c++)
            {
                word[i]=c;
                if(st.count(word)>0)
                {
                    vec.push_back(word);
                    q.push(vec);//mark as visited on the level                    
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
	
}