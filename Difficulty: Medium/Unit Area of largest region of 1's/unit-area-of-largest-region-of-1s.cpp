//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    bool check(int x,int y,vector<vector<int>> &grid){
        if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1) return true;
        return false;
    }
    
    void dfs(int &count,int x,int y,vector<vector<int>> &grid){
        
        grid[x][y] = -1;
        int dx[] = {-1,1,0,0,1,1,-1,-1};
        int dy[] = {0,0,-1,1,-1,1,-1,1};
        count++;
        
        for(int i=0; i<8; i++){
            
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            
            if(check(nx,ny,grid)){
                dfs(count,nx,ny,grid);
            }
        }
        
      
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    int c = 0;
                    dfs(c,i,j,grid);
                    count = max(count,c);
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends