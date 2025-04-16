//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        
        map<int,vector<int>> graph;
        vector<int> inorder(N,0);
        
        for(int i=0; i<P; i++){
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;
            graph[u].push_back(v);
            inorder[v]++;
        }
        
        int completed = 0;
        queue<int> q;
        
        for(int i=0; i<N; i++){
            if(inorder[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            
            int task = q.front();
            q.pop();
            completed++;
            
            for(auto neigh : graph[task]){
                inorder[neigh]--;
                if(inorder[neigh] == 0) q.push(neigh);
            }
    
        }
        
        return (completed == N);
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends