class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n=a.size();
    int posp=0;
    int negp=1;
    vector<int> ar(n,0);
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            ar[posp]=a[i];
            posp+=2;
        }
        else
        {
            ar[negp]=a[i];
            negp+=2;
        }
    }
    return ar;
    }
};