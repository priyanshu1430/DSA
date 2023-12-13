int longestSubarrayWithSumK(vector<int> nums, long long k) {
    int n=nums.size();
    int left=0;
    int right=0;
    long long sum=nums[0];
    int maxlen=0;

    while(right<n)
    {
        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n)
            sum+=nums[right];
        while(left<=right&&sum>k)
        {
            sum-=nums[left];
            left++;
        }
        
    }
    return maxlen;
}