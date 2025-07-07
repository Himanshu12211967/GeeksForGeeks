class Solution {

  public:
  
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        
        if(i == a.length() && j == b.length()) return 0;
        if(i == a.length() && j < b.length()) return b.length()-j;
        if(i < a.length() && j == b.length()) return a.length()-i;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == b[j]){
            return dp[i][j] = solve(a,b,i+1,j+1,dp);
        }
        else{
            int opt1 = 1 + solve(a,b,i,j+1,dp); // insertion
            int opt2 = 1 + solve(a,b,i+1,j,dp); // deletion
            return dp[i][j] = min(opt1,opt2);
        }
        
    }
    
    
    int solve2(string &s1, string &s2){
        
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        
        for(int i=s1.length()-1; i>=0; i--){
            for(int j=s2.length()-1; j>=0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        
        return dp[0][0];
    }
  
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        // vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        // return solve(s1,s2,0,0,dp);
        return s1.length() + s2.length() - 2 * solve2(s1,s2);
    }
};