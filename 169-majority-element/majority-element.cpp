class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can , count=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                can=nums[i];
            }
            else{
                if(can==nums[i])
                count++;
                else
                count--;
            }
        }
        return can;
    }
};