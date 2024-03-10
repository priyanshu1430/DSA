class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> mpp;
        for(char &c: s)
        mpp[c]++;
        for(char &c: t)
        mpp[c]--;
        for(auto x:mpp)
        {
            if(x.second!=0)
                return false;
        }
        return true;
    }
};//use array -a mapping for betetr time complexity