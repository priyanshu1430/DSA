void dfs(int node,int visited[],vector<int>adj[],vector<int> &ls)
{
    visited[node]=1;
    ls.push_back(node);
    for(auto it:adj[node])
    {
        if(!visited[it])
            dfs(it,visited,adj,ls);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    int visited[V]={0};
    vector<vector<int>> ans;
    vector<int> adj [V];
    for(int i=0;i<edges.size();i++)//prepare adjacency lis 
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {    vector<int> ls;
            dfs(i,visited,adj,ls);
            ans.push_back(ls);
        }
    }
    return ans;
    
}