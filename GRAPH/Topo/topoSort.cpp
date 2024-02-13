#include<bits/stdc++.h>
void dfs(int idx, vector<vector<int>> &g, stack<int> &st, int vis[]){
    if(vis[idx])
        return ;
    vis[idx] = 1;
    for(int next : g[idx])
        dfs(next, g, st, vis);

    st.push(idx);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<vector<int>> g(nodes);
    for(vector<int> edge : graph)
        g[edge[0]].push_back(edge[1]);
    stack<int> st;
    int vis[nodes]={0};
    for(int i = 0; i < nodes; i++){
        if(!vis[i]){
            dfs(i, g, st, vis);
        }
    }
   vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();  
    }
    return ans;
}