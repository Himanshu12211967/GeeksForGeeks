class Solution {
  public:
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> inorder(V,0);
        map<int,vector<int>> mapp;
        
        
        for(auto val : edges){
            int a = val[0];
            int b = val[1];
            mapp[a].push_back(b);
            inorder[b]++;
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i=0; i<V; i++){
           if(inorder[i]  == 0) q.push(i);
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto val : mapp[node]){
                inorder[val]--;
                if(inorder[val] == 0) q.push(val);
            }
            
        }
        
        return ans;
    }
};