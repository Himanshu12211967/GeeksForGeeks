//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int solve(string &a, string &b, int i, int j,vector<vector<int>> &dp){
        
        if(i == a.length() || j == b.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == b[j]) return dp[i][j] = 1 + solve(a,b,i+1,j+1,dp);
        else return dp[i][j] = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        
    }
  
    int longestPalinSubseq(string &s) {
        // code here
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        string str = s;
        reverse(str.begin(),str.end());
        return solve(s,str,0,0,dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends