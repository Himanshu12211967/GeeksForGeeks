//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
    public:
    
    bool check(int x,int y,vector<vector<char>> &grid){
        if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 'X') return true;
        return false;
    }
    
    void dfs(int x,int y,vector<vector<char>> &grid){
        
        grid[x][y] = '$';
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int i=0; i<4; i++){
            
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            
            if(check(nx,ny,grid)){
                dfs(nx,ny,grid);
            }
        }
      
    }
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 'X'){
                    dfs(i,j,grid);
                    count++;
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends