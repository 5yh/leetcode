class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx=0;
        int minPrice=999999999;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<minPrice)
            {
                minPrice=prices[i];
            }else if(prices[i]-minPrice>maxx)
            {
                maxx=prices[i]-minPrice;
            }
        }
    }
};