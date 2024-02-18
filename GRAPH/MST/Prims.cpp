#include<bits/stdc++.h>
using namespace std;

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
     vector<vector<int>> graph[n];  
     for(auto edge : edges)
     {    
        int u = edge[0];
        int v= edge[1];
        int wt=edge[2];    
        graph[u].push_back({v, wt});    
        graph[v].push_back({u, wt});  
    }
    priority_queue<pair<int, int>,
        vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n, 0);
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;
        for (auto neighbor : graph[node]) {
            int adjNode = neighbor[0];
            int edW = neighbor[1];
            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }

    return sum;
}
