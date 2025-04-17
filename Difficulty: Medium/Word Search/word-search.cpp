//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool find(string &word,vector<vector<char>>& mat,int &n, int &m, int x, int y, int idx){
        
        if(idx == word.length()) return true;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        char original = mat[x][y];
        mat[x][y] = '$';
        
        for(int i=0; i<4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == word[idx]){
                if(find(word,mat,n,m,nx,ny,idx+1)) return true;
            }
            
        }
        
        mat[x][y] = original;
        return false;
        
    }
  
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0] == mat[i][j] && find(word,mat,n,m,i,j,1))
                    return true;
            }
        }
        
        return false;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends