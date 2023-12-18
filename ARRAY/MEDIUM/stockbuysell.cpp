int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int n=prices.size();
    int minp=INT_MAX;
    int maxprofit=0;
    for(int i=0;i<n;i++)
    {
        minp=min(minp,prices[i]);
        maxprofit=max(maxprofit,(prices[i]-minp));
    }
    return maxprofit;
}
