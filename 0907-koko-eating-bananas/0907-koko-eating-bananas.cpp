class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low=1;
        long long ans=0;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            long totalhours=0;
            int mid=(low+high)/2;
            for(int i=0;i<n;i++){
                totalhours+=(piles[i]+mid-1)/mid;
            }
            if(totalhours<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
            return ans;
    }
};


