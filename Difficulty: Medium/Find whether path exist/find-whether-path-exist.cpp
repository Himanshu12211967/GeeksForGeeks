//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    bool solve(int sx, int sy, int dstx, int dsty,vector<vector<int>> &grid, int n, int m){
        
        
        if(sx == dstx && sy == dsty) return true;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        int original = grid[sx][sy];
        grid[sx][sy] = -1;
        
        for(int i=0; i<4; i++){
            
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != 0 && grid[nx][ny] != -1){
                if(solve(nx,ny,dstx,dsty,grid,n,m)) return true;
            }
            
        }
        
        grid[sx][sy] = original;
        return false;
        
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int m = grid[0].size();
        pair<int,int> src;
        pair<int,int> dst;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m;  j++){
                if(grid[i][j] == 1){
                    src = {i,j};
                }
                if(grid[i][j] == 2){
                    dst = {i,j};
                }
            }
        }
        
        return solve(src.first,src.second,dst.first,dst.second,grid,n,m);
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends