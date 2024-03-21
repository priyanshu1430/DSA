class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int  sum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++)// starting with firt k cards
            sum+=cardPoints[i];
        int maxSum=sum;
        for(int i=k-1;i>=0;i--)
        {
            sum-=cardPoints[i];// rmoving the k index card
            sum+=cardPoints[n-k+i];//chacking for the last right side card
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
}; 