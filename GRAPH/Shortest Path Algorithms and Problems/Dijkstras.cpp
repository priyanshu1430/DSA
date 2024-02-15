#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<pair<int,int>> adj[vertices+1];
    for (int i = 0; i < edges; i++) {
        adj[edge[i][0]].push_back({edge[i][1],edge[i][2]});
        adj[edge[i][1]].push_back({edge[i][0],edge[i][2]});
    }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push({0, source});
    vector<int> dist(vertices,1e9),parent(vertices);
    for(int i=1;i<=vertices;i++)
        parent[i]=i;
    dist[source]=0;
   
    while(!pq.empty())
    {
        auto it=pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for(auto it:adj[node])
        {
            int adjNode=it.first;
            int edW=it.second;
            if(dis+edW<dist[adjNode])
            {
               dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode}); 
                parent[adjNode]=node;
            }
        }
    }
    return dist;
} 