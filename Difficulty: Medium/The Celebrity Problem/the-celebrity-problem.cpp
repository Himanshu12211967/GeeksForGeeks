class Solution {
  public:
  
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        
        for(int i=0; i<n; i++){
            
            int count = 0,count1 = 0;
            
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1) count++;
            }
            
            for(int k=0; k<n; k++){
                if(mat[k][i] == 1) count1++;
            }
            
            if(count == 1 && count1 == n) return i;
        }
        
        return -1;
        
    }
};