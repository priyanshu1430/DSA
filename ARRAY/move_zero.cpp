vector<int> moveZeros(int n, vector<int> a) {
    int i,j,temp;
    j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=0&&a[j]==0)
        {
            a[j]=a[i];
            a[i]=0;
        }
        if(a[j]!=0)
            j++;
    }
    
    return a;
}
