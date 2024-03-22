#include<bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    int n=str.size();
    unordered_map<char,int> mpp;
    int left=0,right=0;
    int  ans=-1;
    while(right<n)
    {
        mpp[str[right]]++;
        while(mpp.size()>k)
        {
            mpp[str[left]]--;
            if(mpp[str[left]]==0)
                mpp.erase(str[left]);
            left++;
        }
        
            ans=max(ans,right-left+1);
        right++;
    }
    return ans;
}


