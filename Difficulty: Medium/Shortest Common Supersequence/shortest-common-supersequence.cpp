// User function template for C++

class Solution {
  public:
  
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
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        return s1.length()+s2.length()-solve2(s1,s2);
    }
};