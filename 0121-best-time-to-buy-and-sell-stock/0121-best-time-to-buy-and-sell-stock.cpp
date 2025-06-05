class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int maxprofit=0;
         int minprize=prices[0];
         for(int i=0;i<prices.size();i++){
            if(prices[i]<minprize){
                minprize=prices[i];
            }else{
                maxprofit=max(maxprofit,prices[i]-minprize);
            }
         }
         return maxprofit;
    }
};