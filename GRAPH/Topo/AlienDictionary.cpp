vector<int> topoSort(int V, vector<int> adj[]){
    int indegree[V] = {0};
    for(int i=0; i<V; i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }  
    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo;
}
string getAlienLanguage(vector<string> &dictionary, int k){
    vector<int>adj[k];
    int n = dictionary.size();

    for(int i=0; i<n-1; i++){
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];

        for(int j=0; j<min(s1.size(), s2.size()); j++){
            if(s1[j] != s2[j]){
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(k, adj); 
    string ans = "";
    for(auto it:topo){
        ans += char(it + 'a');
    }
    return ans;
}
