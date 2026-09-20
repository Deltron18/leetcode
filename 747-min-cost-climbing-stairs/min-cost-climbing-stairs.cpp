//top-down approach


// class Solution {
// public:
// int ways(int n, vector<int>& cost,vector<int>& dp){
//     if(n<=1)
//     return 0;
//     if(dp[n]!=-1)
//     return dp[n];
//     return dp[n]=min((cost[n-1]+ways(n-1,cost,dp)),(cost[n-2]+ways(n-2,cost,dp)));
// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int>dp(n+1,-1);
//         return ways(n,cost,dp);
//     }
// };


//bottom up approach
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost){
    int n=cost.size();
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=min((cost[i-1]+dp[i-1]),cost[i-2]+dp[i-2]);
    }
    return dp[n];
}};