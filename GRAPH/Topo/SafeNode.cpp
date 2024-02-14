class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adjRev[n];
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adjRev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;

    }
};

//code studio
#include <bits/stdc++.h> 
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
  vector<int>adjRev[n];
        vector<int> indegree(n,0);
        for(int i=0;i<e;i++)
        {
                adjRev[edges[i][1]].push_back(edges[i][0]);
                indegree[edges[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adjRev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
}