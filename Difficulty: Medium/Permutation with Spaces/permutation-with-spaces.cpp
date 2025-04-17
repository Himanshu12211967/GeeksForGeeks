//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void solve(vector<string> &ans, string &str, string temp){
        
        if(str.empty()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        for(int i=1; i<=str.length(); i++){
            string sub = str.substr(0,i);
            string rem = str.substr(i);
            solve(ans,rem,temp+sub+' ');
        }
        
    }

    vector<string> permutation(string s) {
        // Code Here
        
        vector<string> ans;
        
        solve(ans,s,"");
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends