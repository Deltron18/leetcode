class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int fre = 0 , ans =0 , n=nums.size();
       for(int i =0;i<n;i++){
        if(fre==0){
            ans= nums[i];
        }
        if(ans==nums[i])
        fre++;
        else
        fre--;
       }
       return ans;
    }
};