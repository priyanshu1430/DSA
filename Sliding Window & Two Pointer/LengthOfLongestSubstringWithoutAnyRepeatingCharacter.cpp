class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int n=s.size();
        int left=0,right=0,maxCount=0,result=0;
        while(right<n)
        {
            count[s[right]-'A']++;
            maxCount=max(maxCount,count[s[right]-'A'])
            if(right-left+1 -maxCount >k)
            {
                count[s[left]-'A']--;
                left++;
            }
            result=max(result,right-left+1);
            right++
        }
        return result;
    }
};