#include<bits/stdc++.h>
int minimumOperations(int n, int start, int end, vector<int> &a)
{
    if(start==end)
        return 0;
    queue<pair<int,int>> q;
    q.push({start,0});
    vector<int> dist(1000,1e9);
    dist[start]=0;
    int mod=1000;
    while (!q.empty())
     {
         int node=q.front().first;
         int steps=q.front().second;
         q.pop();
         for(auto it:a)
         {
             int num=(it*node)%mod;
             if(steps+1<dist[num]){
                 dist[num]=steps+1;
                 if(num==end)
                    return steps+1;
                 q.push({num, steps + 1});
             }
         }
    }
    return -1;
}