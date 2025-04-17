//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    bool check(int x,int y,int n,int m,vector<vector<int>> &matrix){
        if(x >= 0 && y >= 0 && x < n && y < m){
            if(matrix[x][y] != 0) return true;
            if(x == n-1 && y == m-1) return true;
        }
        return false;
    }

    bool solve(vector<vector<int>>&matrix,vector<vector<int>>&ans,int x,int y,int n,int m){
        
        int jump = matrix[x][y];
        matrix[x][y] = 0;
        ans[x][y] = 1;
        
        if(x == n-1 && y == m-1){
            return true;
        }
        
        for(int i=1; i<=jump; i++){
            
            if(check(x,y+i,n,m,matrix)){
                if(solve(matrix,ans,x,y+i,n,m)) return true;
            }
        
            if(check(x+i,y,n,m,matrix)){
                if(solve(matrix,ans,x+i,y,n,m)) return true;
            }
                
        }

        matrix[x][y] = jump;
        ans[x][y] = 0;
        return false;
        
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   if(matrix.size() == 1) return {{1}};
	    if(matrix[0][0] == 0) return {{-1}};
	    vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),0));
	    if(solve(matrix,ans,0,0,matrix.size(),matrix[0].size())){
	        return ans;
	    } 
	    return {{-1}};
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends