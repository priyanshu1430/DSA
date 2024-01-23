vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    int visited[n]={0};
    visited[0]=1;//starting node
    queue<int> q;
    q.push(0);//adding to queue
    vector<int> bfs;

    while(!q.empty())
    {
        int node =q.front(); // Dequeue a vertex from queue and print it
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node])// Get all adjacent vertices of the dequeued
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}