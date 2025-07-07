class Solution {
  public:
  
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        
        vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),0));
        int ans = 0;
        
        for(int i=0; i<s1.length(); i++){
            for(int j=0; j<s2.length(); j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1;
                    if(i-1 >= 0 && j-1 >= 0) dp[i][j] += dp[i-1][j-1];
                }
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
        
    }
};