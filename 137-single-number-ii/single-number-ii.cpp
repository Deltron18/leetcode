class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()<2)
        return nums[0];
         int first,third,fourth;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<=nums.size()-4){
        first=nums[i];
        third=nums[i+2];
        fourth=nums[i+3];

        if(first!=third)
        return first;
       
       i+=3;

        }
    return fourth;
    }
};