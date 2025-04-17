//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(set<string> &ans,string s,int index,string temp){
        
        if(index == s.length()){
            ans.insert(temp);
            return;
        }
        
        for(int i=index; i<s.length(); i++){
            swap(s[index],s[i]);
            temp.push_back(s[index]);
            solve(ans,s,index+1,temp);
            temp.pop_back();
            swap(s[index],s[i]);
        }
        
        
    }
  
    vector<string> findPermutation(string &s) {
        // Code here there
    
        set<string> temp;
        solve(temp,s,0,"");
        vector<string> ans(temp.begin(),temp.end());
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
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends