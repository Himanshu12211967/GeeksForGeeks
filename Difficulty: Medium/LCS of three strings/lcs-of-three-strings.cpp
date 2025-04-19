//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(string a,string b,string c,int i,int j,int k,vector<vector<vector<int>>> &dp){
        
        if(i == a.length() || j == b.length() || k == c.length()) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        
        if(a[i] == b[j] && b[j] == c[k]){
            return dp[i][j][k] = 1+solve(a,b,c,i+1,j+1,k+1,dp);
        }
        else{
            return dp[i][j][k] = max({solve(a,b,c,i+1,j,k,dp),solve(a,b,c,i,j+1,k,dp),solve(a,b,c,i,j,k+1,dp)});
        }
        
    }
    
    
    int tabulation(string &a,string &b,string &c){
        
        vector<vector<vector<int>>> dp(a.length()+1,vector<vector<int>>(b.length()+1,vector<int>(c.length()+1,0)));
        
        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
                for(int k=c.length()-1; k>=0; k--){
                    if(a[i] == b[j] && b[j] == c[k]){
                        dp[i][j][k] = 1+dp[i+1][j+1][k+1];
                    }
                    else{
                        dp[i][j][k] = max({dp[i+1][j][k],dp[i][j+1][k],dp[i][j][k+1]});
                    }
                }
            }
        }
        
        return dp[0][0][0];
        
    }

    int LCSof3(string& s1, string& s2, string& s3) {
        // your code here
        
        //vector<vector<vector<int>>> dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
        return tabulation(s1,s2,s3);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        // int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cin.ignore();
        Solution obj;
        cout << obj.LCSof3(s1, s2, s3) << endl;

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends