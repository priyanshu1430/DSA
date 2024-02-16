class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});   
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector <int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int distance=it.second;
                if(dis+distance<dist[adjNode])
                {
                    dist[adjNode]=dis+distance;
                    pq.push({dis+distance,adjNode});
                }
            }
        }
        int ans =-1;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dist[i]);
        }
        if(ans==1e9)
            return -1;
        else
            return ans;
    }
};