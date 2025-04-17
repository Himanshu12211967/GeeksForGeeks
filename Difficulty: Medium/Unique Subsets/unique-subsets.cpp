//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    void solve(set<vector<int>> &s,vector<int> temp,vector<int> arr,int i,int n)
    {
        if(i == n){
            s.insert(temp);
            return;
        }
        
        
        int val = arr[i];
        temp.push_back(val);
        solve(s,temp,arr,i+1,n);
        temp.pop_back();
        
        solve(s,temp,arr,i+1,n);
        
        
        
    }//Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        set<vector<int>> s;
        solve(s,temp,arr,0,n);
        
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    
cout << "~" << "\n";
}
}   



// } Driver Code Ends