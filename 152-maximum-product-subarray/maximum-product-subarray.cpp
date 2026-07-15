class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],minend=nums[0],maxend=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=minend*nums[i];
            int v3=maxend*nums[i];

            minend=min(v1,min(v2,v3));
            maxend=max(v1,max(v2,v3));

            ans=max(ans,max(minend,maxend));
        }
        return ans; 
    }
};