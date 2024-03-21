class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0;
        int n=s.size();
        int ans=0;
        unordered_map<char,int> mp;
        while(right<n)
        {
            mp[s[right]]++;
            while(mp['a']&&mp['b']&&mp['c'])
            {
                ans+=n-right;//all the substring after this ,including this will be valid substirng
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};