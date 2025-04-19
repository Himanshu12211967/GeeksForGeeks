//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        vector<int> ans(1,1);
        int carry = 0;
        
        while(n != 0 || carry != 0){
            
            for(int i=0; i<ans.size(); i++){
                
                int num = ans[i];
                int product = num * n + carry;
                carry = product / 10;
                product %= 10;
                ans[i] = product;
                
            }
            
            while(carry){
                int num = carry%10;
                ans.push_back(num);
                carry /= 10;
            }
            
            n--;
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends