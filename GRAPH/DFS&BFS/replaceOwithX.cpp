class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& arr,int n,int m)
{
    vis[row][col]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m&& !vis[nrow][ncol] && arr[nrow][ncol]=='O' )
             dfs(nrow,ncol,vis,arr,n,m);
    }
}
    void solve(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
      for(int j=0;j<m;j++)//traverse the first the row and the last row
      {
          if(!vis[0][j]&&arr[0][j]=='O')
          {
              dfs(0,j,vis,arr,n,m);
          }
          if(!vis[n-1][j]&&arr[n-1][j]=='O')
          {
              dfs(n-1,j,vis,arr,n,m);
          }
      }
       for(int i=0;i<n;i++)//traverse the first the column and the last column
      {
          if(!vis[i][0]&&arr[i][0]=='O')
          {
              dfs(i,0,vis,arr,n,m);
          }
          if(!vis[i][m-1]&&arr[i][m-1]=='O')
          {
              dfs(i,m-1,vis,arr,n,m);
          }
      }
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
         {
              if(!vis[i][j]&&arr[i][j]=='O')
                arr[i][j]='X';
         }
}
    
};