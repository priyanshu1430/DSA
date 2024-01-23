vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> ans(n);
  for(int i=0;i<n;i++)// Initialize each vertex with itself in its adjacency list
  {
        ans[i].push_back(i);
    } 
    for (int i=0;i<m;i++)// Add edges to the adjacency list
    {
        ans[edges[i][0]].push_back(edges[i][1]);
        ans[edges[i][1]].push_back(edges[i][0]);
    }
   return ans; 
}