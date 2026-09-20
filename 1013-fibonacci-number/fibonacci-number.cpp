class Solution {
public:

int fibn(int n, vector<int>&dp){

    if(n<=1)
    return n;
    
    if(dp[n]!=-1)
    return dp[n];

    return dp[n]=fibn(n-1,dp)+fibn(n-2,dp);
}

    int fib(int n) {
         vector<int>dp(n+1,-1); 
         return fibn(n,dp);
    }
};