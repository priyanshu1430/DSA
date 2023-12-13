vector<int> getSecondOrderElements(int n, vector<int> a) {
    int l1=a[0],l2=-1,s1=a[0],s2=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if (s1>a[i]){
            s2=s1;
            s1=a[i];
        }
        if(a[i]!=l1&&a[i]>l2)
            l2=a[i];
        if (l1<a[i]){
            l2=l1;
            l1=a[i];
        }
        if(a[i]!=s1&&a[i]<s2)
            s2=a[i];
    }
   return {l2,s2};
}
