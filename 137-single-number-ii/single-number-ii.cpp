class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()<2)
        return nums[0];
        int ans;
        sort(nums.begin(),nums.end());
    int i=0;
        while(i<=nums.size()-4){
            if(nums[i]==nums[i+2])
           {
             ans=nums[i+3];
              i=i+3;
          
           }
        else{
            return nums[i];
        }
        }
return ans;
    }
};