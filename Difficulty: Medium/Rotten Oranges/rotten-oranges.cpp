//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,int>> q;
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 2) q.push({i,j});
            }
        }
        
        int timer = 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while(!q.empty()){
            
            int size = q.size();
            bool flag = false;
            
            for(int i=0; i<size; i++){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0; i<4; i++){
                
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx >= 0 && ny >= 0 && nx < mat.size() && ny < mat[0].size() && mat[nx][ny] == 1){
                        mat[nx][ny] = 2;
                        q.push({nx,ny});
                        flag = true;
                    }
                
                }
            }
            
            if(flag) timer++;
        }
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 1) return -1;
            }
        }
        
        return timer;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends