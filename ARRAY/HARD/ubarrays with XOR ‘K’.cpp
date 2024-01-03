#include<map>
int subarraysWithSumK(vector < int > a, int b) {
    int n=a.size();
    int xr=0;
    int cnt=0;
    map<int,int> mp;
    mp[xr]=1;//{0,1} 0 one time
    for(int i=0;i<n;i++)
    {
        xr=xr^a[i];
        int x=b^xr;
        cnt+=mp[x];
        mp[xr]++;
    }
    return cnt;
}