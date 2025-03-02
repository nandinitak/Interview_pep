class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
     
        vector<vector<int>> nums3;
        int j=0,i=0;
        while(i<n && j<m){
            vector<int>ds;
             if (nums1[i][0] == nums2[j][0]) {
                ds.push_back(nums1[i][0]);
                ds.push_back(nums1[i][1]+nums2[j][1]);
                nums3.push_back(ds);
                i++;
                j++;
        }else if(nums1[i][0]<nums2[j][0]){
            nums3.push_back(nums1[i]);
            i++;

        }else{
            nums3.push_back(nums2[j]);
           j++;
        }
      
    }
    while(i<n){
        nums3.push_back(nums1[i]);
        i++;
    }
     while(j<m){
        nums3.push_back(nums2[j]);
        j++;
    }

      return nums3;
    }
};