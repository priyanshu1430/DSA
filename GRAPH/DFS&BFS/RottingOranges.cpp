class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;//{{r,c}t}
        vector<vector<int>>visited(n,vector<int>(m));
        int fresh = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                 }
                else if(grid[i][j] == 1)
                 {
                    fresh++;
                }
            }
        }
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2)
                 {   
                     visited[nrow][ncol]=2;
                     q.push({{nrow,ncol},t+1});
                     fresh--;
                 }
            }
        }
        if(fresh != 0) return -1;
        return tm;

    }
};