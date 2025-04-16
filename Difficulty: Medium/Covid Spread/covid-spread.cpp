//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    bool isvalid(int x,int y,vector<vector<int>> &hospital,int n,int m){
        return (x >= 0 && y >= 0 && x < n && y < m && hospital[x][y] == 1);
    }

    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n = hospital.size();
        int m = hospital[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(hospital[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int timer = 0;
        while(!q.empty()){
            
            int size = q.size();

            int dx[] = {0,0,-1,1};
            int dy[] = {1,-1,0,0};
            
            for(int i=0; i<size; i++){
            
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
            
                for(int i=0; i<4; i++){
                    
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(isvalid(nx,ny,hospital,n,m)){
                        hospital[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                    
                }
            }
            
            timer++;
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(hospital[i][j] == 1) return -1;
            }
        }
        
        if(timer == 0) return 0;
        return timer-1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends