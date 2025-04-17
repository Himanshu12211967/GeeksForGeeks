//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    bool check(int x,int y,int n,int m){
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    void solve(vector<vector<int>> &ans,int n,int m,vector<vector<int>> &grid,int x,int y,vector<int> temp){
        
        if(x == n-1 && y == m-1){
            temp.push_back(grid[x][y]);
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(grid[x][y]);
        
        if(check(x+1,y,n,m)){
            solve(ans,n,m,grid,x+1,y,temp);
        }
        
        if(check(x,y+1,n,m)){
            solve(ans,n,m,grid,x,y+1,temp);
        }
  
        temp.pop_back();
        
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,n,m,grid,0,0,temp);
        //cout<<n<<m;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends