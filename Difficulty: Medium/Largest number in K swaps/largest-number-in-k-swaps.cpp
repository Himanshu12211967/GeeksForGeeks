//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
    void solve(string str,string &ans,int k,int index){
        
        if(k == 0 || index == str.length()) return;
        
        for(int i=index+1; i<str.length(); i++){
            
            if(str[index] < str[i]){
                swap(str[index],str[i]);
                if(str > ans) ans = str;
                solve(str,ans,k-1,index+1);
                swap(str[index],str[i]);
            }
        
        }
        
        solve(str,ans,k,index+1);
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans = s;
        solve(s,ans,k,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends