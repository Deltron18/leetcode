class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1,count=1,n=nums.size();
        while(j<n){
            if(nums[j]==nums[j-1]){
                j++;
            }else{
                nums[i+1]=nums[j];
                i++;
                j++;
                count++;
            }
        }
        return count;
    }
};