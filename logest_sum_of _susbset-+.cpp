#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    int n=nums.size();
    map<int,int> startsum;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum==k)
        {
            maxlen=max(maxlen,i+1);
        }        
         if(startsum.find(sum)==startsum.end())
        {
            startsum[sum]=i;
        }
        int rem=sum-k;
        if(startsum.find(rem)!=startsum.end())
        {
            maxlen=max(maxlen,i-startsum[rem]);
        }
       
    }

    return maxlen;

}