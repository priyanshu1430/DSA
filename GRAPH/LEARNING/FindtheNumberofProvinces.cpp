void traversal(int idx,vector<vector<int>>& roads,vector<int> & visited){
    for(int i=0;i<roads.size();i++){
        if(roads[idx][i]==1 && visited[i]==0 && idx!=i){
            visited[i]=1;
        traversal(i, roads,visited);
        }
    }
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    int ans =0;
    vector<int> visited(n,0);
    for(int i =0;i<n;i++)//using Disjoint approach
    {
        if(!visited[i])
        {
            traversal(i,roads,visited);
            ans++;//counting the number of breaks
        }
    }
    return ans;
}