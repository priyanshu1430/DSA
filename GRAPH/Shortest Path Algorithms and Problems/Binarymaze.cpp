class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    pair<int,int>dest={n-1,m-1};
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    queue<pair<int, pair<int, int>>> q;
    if(matrix[0][0] == 1 ) 
        return -1;
    if(n-1 == 0)
            return 1;
    dist[0][0] = 0;
    q.push({1, {0,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int col = it.second.second;
        int row = it.second.first;
        if(row == n-1 && col==m-1)
                return dis;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
        {
            int nrow = row +i;
            int ncol = col +j;
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && matrix[nrow][ncol] ==0 
            && (dis + 1 < dist[nrow][ncol])){
                dist[nrow][ncol] = dis + 1;
                if(nrow==dest.first&&ncol==dest.second)
                    return dist[nrow][ncol];
                q.push({dist[nrow][ncol],{nrow , ncol }});
            }
        }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j] == 1e9){
                dist[i][j] = -1;
            }
        }
    }
    return dist[dest.first][dest.second];
    }
};

//code studio

#include <bits/stdc++.h> 
int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    queue<pair<int, pair<int, int>>> q;
    if(matrix[src.first][src.second] == 0 ) return -1;
    dist[src.first][src.second] = 0;
    q.push({0 , {src.first,src.second}});
    int delRow[4] = {-1,0,1,0};
    int delCol[4] = {0,1,0,-1};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int col = it.second.second;
        int row = it.second.first;
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && matrix[nrow][ncol] == 1 
            && (dis + 1 < dist[nrow][ncol])){
                dist[nrow][ncol] = dis + 1;
                if(nrow==dest.first&&ncol==dest.second)
                    return dist[nrow][ncol];
                q.push({dist[nrow][ncol],{nrow , ncol }});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j] == 1e9){
                dist[i][j] = -1;
            }
        }
    }
    return dist[dest.first][dest.second];
    
}