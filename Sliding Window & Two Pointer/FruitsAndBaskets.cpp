#include <vector>
#include <unordered_map>
int findMaxFruits(vector<int> &r, int n) {
   unordered_map<int,int> mpp;
   int ans=0;
   int left=0,right=0;
   while(right<n)
   {
       mpp[r[right]]++;
       while(mpp.size()>2)
       {
           mpp[r[left]]--;
           if(mpp[r[left]]==0)
                mpp.erase(r[left]);
          left++;
       }
        ans=max(ans,right-left+1);
        right++;
   }
   return ans;
}