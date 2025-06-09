class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice= prices[0];
        int maxprice=0;
        int maxdiff=0;
        int sum=0;
        int n=  prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<minprice){
                minprice=prices[i];
            }
            if(prices[i]>minprice){
                maxdiff= prices[i]-minprice;
                sum+=maxdiff;
                minprice=prices[i];
            }
            maxdiff=0;
        }
        return sum;

    }
};