//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{   
public:

    int solve(vector<int>arr, int sum,int idx,vector<vector<int>> &dp){
        
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        if(idx >= arr.size()) return 0;
        if(dp[sum][idx] != -1) return dp[sum][idx];
        
        
        return dp[sum][idx] = solve(arr,sum-arr[idx],idx+1,dp) || solve(arr,sum,idx+1,dp);
        
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(sum+1,vector<int>(arr.size()+1,-1));
        if(solve(arr,sum,0,dp) == 1) return true;
        return false;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends