class Solution {
  public:
  
    int solve(int n,vector<int> &dp){
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        
        int opt1 = solve(n-1,dp);
        int opt2 = solve(n-2,dp);
        return dp[n] = opt1 + opt2;
        
    }
  
    int numberOfWays(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};