class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int me=0;
        for(int i=0;i<nums.size();i++){
            me=max(me,nums[i]);
        }
        int s=0,e=0,count=0;
        long long total=0;
        while(e<nums.size()){
            if(nums[e]==me)
            count++;
            while(count==k){
                total+=nums.size()-e;
                if(nums[s]==me){
                    count--;
                }
                s++;
            }
            e++;
        }
        return total; 
    }
};