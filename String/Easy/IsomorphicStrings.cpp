class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        unordered_map<char,char> mp1,mp2;
        if(n1!=n2)
            return false;
        for(int i=0;i<n1;i++)
        {
            if(mp1[s[i]]&&mp1[s[i]]!=t[i]) return false;
            if(mp2[t[i]]&&mp2[t[i]]!=s[i]) return false;
            mp1[s[i]]=t[i];//mapping the characters
            mp2[t[i]]=s[i];
        }
        return true;
    }
};