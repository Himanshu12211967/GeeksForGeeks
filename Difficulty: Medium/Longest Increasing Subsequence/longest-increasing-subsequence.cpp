//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
    // 5 8 3 7 9 1
    
    // 5 5 3 3 3 1
    //   8   7 7
    //         9
  
    int lis(vector<int>& arr) {
        // code here;
        int longest = 0;
        vector<int> dp(arr.size());
        dp[0] = 1;
        
        for(int i=0; i<arr.size(); i++){
            int count = 1;
            for(int j=i-1; j>=0; j--){
                if(arr[j] < arr[i] && dp[j] >= count) count = dp[j]+1;
            }
            dp[i] = count;
            longest = max(longest,dp[i]);
        }
        
        
        return longest;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends