

class Solution {
  public:
  
    int solve(vector<int> &arr,int target,int index,vector<vector<int>> &dp){
        
        if(target < 0) return 0;
        if(index >= arr.size()) return (target==0);
        
        if(dp[index][target] != -1) return dp[index][target];
        
        // include
        int left = solve(arr,target-arr[index],index+1,dp);
        
        //exclude
        int right = solve(arr,target,index+1,dp);
        
        return dp[index][target] = left+right;
        
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>> dp(arr.size()+1,vector<int>(target+1,-1));
        return solve(arr,target,0,dp);
    }
};



