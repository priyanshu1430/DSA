class Solution {
public:
    vector <int> generateP(int row)
{
    vector<int> ansRow;
    int ans=1;
    ansRow.push_back(1);
    for(int col=1;col<row;col++)
    {
        ans*=(row-col);
        ans/=col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
   vector<vector<int>> generate(int N) {
    vector<vector<int>> ans;
    
    for(int i=1;i<=N;i++)
    {
        ans.push_back(generateP(i));
    }
    return ans;
}
};