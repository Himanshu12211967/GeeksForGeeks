//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    void solve(string str,string temp,vector<string> &ans,long prev,long currsum,int target){
        
        if(str.empty()){
            if(target == currsum) ans.push_back(temp);
            return;
        }
        
        for(int i=1; i<=str.length(); i++){
    
            string sub = str.substr(0,i);
            string rem = str.substr(i);
            if(sub.length() > 1 && sub[0] == '0') return;
            long num = stol(sub);
            
            if(temp.empty()){
                solve(rem,sub,ans,num,num,target);
            }
            else{
                
                solve(rem,temp+'+'+sub,ans,num,currsum+num,target);
                solve(rem,temp+'-'+sub,ans,-num,currsum-num,target);
                int result = prev*num+currsum-prev;
                solve(rem,temp+'*'+sub,ans,prev*num,result,target);
                
            }
            
        }
        
    }
  
    vector<string> addOperators(string S, int target) {
        // code here
        vector<string> ans;
        solve(S,"",ans,-1,0,target);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends