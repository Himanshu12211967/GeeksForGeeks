// User function Template for C++

class Solution {
  public:
    int minThrow(int N, int arr[]) {
        // code here
        int start = 1;
        int end = 30;
        unordered_map<int,int> snake_ladder;
        
        int i = 0;
        
        while(i < 2*N){
            
            int a = arr[i++];
            int b = arr[i++];
            snake_ladder[a] = b;
        }
        
        queue<pair<int,int>> q;
        vector<int> visited(31,0);
        q.push({start,0});
        
        while(!q.empty()){
            
            int curr_pos = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(curr_pos == end) return steps;
            
            for(int i=1; i<=6; i++){
                
                int next_pos = curr_pos + i;
                if(next_pos > end) break;
                if(snake_ladder.find(next_pos) != snake_ladder.end()) next_pos = snake_ladder[next_pos];
                if(!visited[next_pos]){
                    visited[next_pos] = 1;
                    q.push({next_pos,steps+1});
                }
                
            }
            
        }
        
        return -1;
    }
};