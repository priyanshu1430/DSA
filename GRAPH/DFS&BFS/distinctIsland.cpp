#include<bits/stdc++.h>
void bfs(int row, int col, vector<vector<int>> &vis, int** grid,vector<pair<int,int>>&temp,int start,int end,int n,int m) {
      vis[row][col] = 1; 
      queue<pair<int,int>> q; 
      q.push({row, col});
       temp.push_back({row-start,col-end});
       int delrow[] = {-1, 0, +1, 0};
       int delcol[] = {0, +1, +0, -1};  
      while(!q.empty()) {
          int row = q.front().first; 
          int col = q.front().second; 
          q.pop(); 
         //and mark them if its a land 
                 for(int i=0; i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                  if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  // neighbour row and column is valid, 
                  && grid[nrow][ncol] ==1 && !vis[nrow][ncol]) {//and is an unvisited land
                      vis[nrow][ncol] = 1; 
                      q.push({nrow, ncol}); 
                      temp.push_back({nrow-start,ncol-end});
                  }
              
          }
      }
  }
int distinctIslands(int** grid, int n, int m)
{
  vector<vector<int>> vis(n, vector<int>(m, 0)); 
        set<vector<pair<int,int>>>st;
        for(int row = 0; row < n ; row++) {
            for(int col = 0; col < m ;col++) {
                if(!vis[row][col] && grid[row][col] == 1) {
                     vector<pair<int,int>>temp;
                    bfs(row, col, vis, grid,temp,row,col,n,m); 
                     st.insert(temp);
                }
            }
        }
      return st.size();
}