vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
   vector<int> adj[n];
   for(auto it:edges)
   {
       adj[it[0]].push_back(it[1]);
       adj[it[1]].push_back(it[0]);
   }
    vector<int>dist(n, INT_MAX);
   for(int i=0;i<n;i++)
   {
       dist[src]=0;
       queue<int> q;
       q.push(src);
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           for(auto it:adj[node])
           {
               if(dist[node]+1<dist[it])
               {
                   dist[it] = dist[node] + 1;
                    q.push(it);
               }
           }
       }

   }
   vector<int> ans(n,-1);
   for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    
    return dist;
}