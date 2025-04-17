//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*complete the Function*/

class Solution {
    
    public:
    void solve(string str,vector<string> &ans,string temp,int parts){
        
        if(str.empty() && parts > 0) return;
        if(parts == 0 && str.empty()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        if(parts == 0 && str.size() > 0) return;
        
        for(int i=1; i<=3; i++){
            if(str.length() < i) return;
            string sub = str.substr(0,i);
            string rem = str.substr(i);
            int num = stoi(sub);
            if(sub.length() > 1 && sub[0] == '0') continue;
            if(num >= 0 && num <= 255){
                solve(rem,ans,temp+sub+'.',parts-1);
            }
        }
        
    }
    
    vector<string> generateIp(string s) {
        // code here
        vector<string> ans;
        solve(s,ans,"",4);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.generateIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else {
            for (auto &u : str) {
                cout << u << "\n";
            }
        }

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends