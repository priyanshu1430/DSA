class Solution {
  public:
  
    void solve(int ind,int sum,vector<int> &arr,int n,vector<int>&ans)
    {
        if(ind==n)
        {
            ans.push_back(sum);
            return;
        }
        solve(ind+1,sum+arr[ind],arr,n,ans);//pick the element
        solve(ind+1,sum,arr,n,ans);//not pick the elemnt
        
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>ans;
         solve(0,0,arr,n,ans);
         sort(ans.begin(),ans.end());
         return ans;
    }
};