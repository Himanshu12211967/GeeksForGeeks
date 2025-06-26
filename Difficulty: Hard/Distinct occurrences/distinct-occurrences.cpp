class Solution {
  public:
  
    int solve(string &txt, string &pat, int i, int j, vector<vector<int>> &dp){
        
        if(j >= pat.length()) return 1;
        if(i >= txt.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int count = 0;
        
        if(txt[i] == pat[j]){
            count += solve(txt,pat,i+1,j+1,dp);
            count += solve(txt,pat,i+1,j,dp);
        }
        else{
            count += solve(txt,pat,i+1,j,dp);
        }
        
        return dp[i][j] = count;
        
    }
  
    int subseqCount(string &txt, string &pat) {
        // code here
        vector<vector<int>> dp(txt.length()+1,vector<int>(pat.length()+1,-1));
        return solve(txt,pat,0,0,dp);
    }
};