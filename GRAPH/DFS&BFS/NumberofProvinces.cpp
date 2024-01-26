class Solution {
public:
void dfs(int node,int visited[],vector<vector<int>>& isConnected)
{
    visited[node]=1;
    for(int i=0;i<isConnected[node].size();i++)
    {
        if(isConnected[node][i]==1&&visited[i]!=1)
            dfs(i,visited,isConnected);
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int visited[n];
        for(int i=0;i<n;i++)
            visited[i]=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};