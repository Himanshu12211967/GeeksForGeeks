//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends

//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void solve(vector<string> &ans, int open, int close, string temp){
        
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }
        
        if(open > 0){
            solve(ans,open-1,close,temp+'(');
        }
        
        if(close > 0 && open < close){
            solve(ans,open,close-1,temp+')');
        }
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        solve(ans,n,n,"");
        return ans;
    }
};


//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends