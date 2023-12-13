int isSorted(int n, vector<int> a) {
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]>=a[i])
        {}
        else if(a[i+1]<a[i])
         return 0;
    }
    return 1;
}
