int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n=arr.size();
    map<int,int> mpp;
    mpp[0]=1;
    int presum=0,rem;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        rem=presum-k;
        cnt+=mpp[rem];
        mpp[presum]+=1;
    }
    return cnt;
}

