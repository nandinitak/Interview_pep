class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int p=0;
        bool f = false;
        int n = nums.size();
        unordered_map<int,int> mpp;
        if(n%2!=0) f= false;
        for(int i=0;i<n;i++){
                mpp[nums[i]]++;
        }
        for(auto i : mpp){
            if(i.second%2==0)
           p+=i.second;
        }
        if(p==n) f= true;
        return f;
    }
};