// User function Template for C++

class Solution {
  public:
  
  
    int solve(vector<vector<int>> &matrix,int n,int m,int x,int y,vector<vector<int>> &dp){
        
        if(dp[x][y] != -1) return dp[x][y];
        int ans = 1;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int i=0; i<4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[x][y] < matrix[nx][ny]){
                int rec = 1 + solve(matrix,n,m,nx,ny,dp);
                ans = max(ans,rec);
            }
        }
        
        return dp[x][y] = ans;
    }
  
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int max_len = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                max_len = max(max_len,solve(matrix,n,m,i,j,dp));
            }
        }
        
        return max_len;
        
    }
};