//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(int i,int j,string str1,string str2,int n,int m,vector<vector<int>> &dp){
      
      
          if(i >= n && j < m) return 0;
          if(j >= m && i < n) return 0;
          if(i >= n && j >= m) return 0;
          if(dp[i][j] != -1) return dp[i][j];
          
          if(str1[i] == str2[j] && i != j){
              return dp[i][j] =  solve(i+1,j+1,str1,str2,n,m,dp)+1;
          }
          else{
              return dp[i][j] = max(solve(i+1,j,str1,str2,n,m,dp),solve(i,j+1,str1,str2,n,m,dp));
          }
      
      
    }
    
    int tab(string str1,string str2,int n,int m){
      
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
          
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(str1[i] == str2[j] && i != j){
                    dp[i][j] =  dp[i+1][j+1]+1;
                }
              else{
                  dp[i][j] = max((dp[i+1][j]),(dp[i][j+1]));
              }
            }
        }
          
        return dp[0][0];
    }
  
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int n = s.length();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return tab(s,s,n,n);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends