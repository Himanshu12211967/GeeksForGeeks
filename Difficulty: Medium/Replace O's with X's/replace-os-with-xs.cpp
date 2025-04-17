//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<char>>& mat, int x, int y){
        
        mat[x][y] = '$';
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int i=0; i<4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < mat.size() && ny < mat[0].size() && mat[nx][ny] == 'O'){
                dfs(mat,nx,ny);
            }
            
        }
        
    }
  
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(i == 0 || j == 0 || i == mat.size()-1 || j == mat[i].size()-1){
                    if(mat[i][j] == 'O'){
                        dfs(mat,i,j);
                    }
                }
            }
        }
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == '$') mat[i][j] = 'O';
                else mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends