class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int kruskalMST(int n, vector<vector<int>> &adj)
{
	vector<pair<int,pair<int,int>>> edges;
		for(auto it:adj)
		{
			int adjNode=it[1];
			int wt=it[2];
			int node=it[0];
			edges.push_back({wt,{node,adjNode}});
		}
	DisjointSet ds(n);
	sort(edges.begin(),edges.end());
	int mstWt=0;
	for(auto it:edges)
	{
		int wt=it.first;
		int u=it.second.first;
		int v=it.second.second;
		if(ds.findUPar(u)!=ds.findUPar(v))
		{
			mstWt+=wt;
			ds.unionByRank(u,v);
		}
	}
	return mstWt;
}
