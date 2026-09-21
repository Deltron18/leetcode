class Solution {
public:

int robber(int i,vector<int>& nums,vector<int>& dp){
    if(i==0)
    return nums[0];

    if(i==1)
    return max(nums[0],nums[1]);

    if(dp[i]!=-1)
    return dp[i];

    return dp[i]=max((nums[i]+robber(i-2,nums,dp)),robber(i-1,nums,dp));
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        int i;
        vector<int>dp(n,-1);
        return robber(n-1,nums,dp);
    }
};





// class Solution {
// public:
//     int rob(vector<int>& nums) {
        
//     }
// };