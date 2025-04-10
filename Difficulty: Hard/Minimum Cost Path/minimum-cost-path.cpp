//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        vector<vector<int>> board(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        
        q.push({0,0});
        board[0][0] = grid[0][0];
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int cost = board[x][y];
            
            for(int i=0; i<4; i++){
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && board[nx][ny] > cost+grid[nx][ny]){
                    board[nx][ny] = cost+grid[nx][ny];
                    q.push({nx,ny});
                }
                
            }
    
        }
        
        return board[grid.size()-1][grid[0].size()-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends