long long maxSubarraySum(vector<int> arr, int n)//kadane's algorithm
{
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)// countiong ferom element whose sum will be positive
    {
        sum+=arr[i];
        maxi=max(sum,maxi);
        if(sum<0)
            sum=0;
    }
    if(maxi<0)
        maxi=0;
    return maxi;
}