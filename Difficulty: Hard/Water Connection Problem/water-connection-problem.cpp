//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    void dfs(int house, vector<bool> &visited, int &tap, int &diam, map<int,vector<pair<int,int>>> &connection){
        
        visited[house] = true;
        
        for(auto child : connection[house]){
            if(!visited[child.first]){
                diam = min(diam,child.second);
                tap = child.first;
                dfs(child.first,visited,tap,diam,connection);
            }
        }

        
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        map<int,vector<pair<int,int>>> connection;
        vector<int> tank(n+1,0);
        
        for(int i=0; i<p; i++){
            int u = a[i];
            int v = b[i];
            int dia = d[i];
            connection[u].push_back({v,dia});
            if(tank[u] != -1){
                tank[u] = 1;
            }
            tank[v] = -1;
        }
        
        vector<bool> visited(n+1,false);
        vector<vector<int>> ans;
        
        for(int i=1; i<=n; i++){
            if(!visited[i] && tank[i] == 1){
                int tap,diam = INT_MAX;
                dfs(i,visited,tap,diam,connection);
                ans.push_back({i,tap,diam});
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};



//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends