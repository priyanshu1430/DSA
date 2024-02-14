#include<bits/stdc++.h>

vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites)
{
    int indegree[numCourses]={0};
   for (auto edge : prerequisites) {
        indegree[edge.second]++;
    }
  queue<int> q;
  for(int i=0;i<numCourses;i++)
  {
    if(indegree[i]==0)
      q.push(i);
  }
  vector<int> topo;
  while(!q.empty())
  {
    int node=q.front();
    q.pop();
    topo.push_back(node);
    for (auto it : prerequisites)
    {
      if (it.first == node)
     {
        indegree[it.second]--;
        if (indegree[it.second] == 0)
            q.push(it.second);
       }
    }
  }
  if(topo.size() == numCourses)
    return topo;
  return {};

}