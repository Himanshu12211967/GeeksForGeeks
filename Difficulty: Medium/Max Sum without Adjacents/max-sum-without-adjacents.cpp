// User function template for C++
class Solution {
  public:
  
    int tabulation(vector<int> &arr){
        
        vector<int> dp(arr.size()+1,0);
        
        
        for(int i=arr.size()-1; i>=0 ; i--){
            int nottake = dp[i+1];
            int take = arr[i];
            if(i+2 < dp.size()) take += dp[i+2];
            dp[i] = max(take,nottake);
        }
        
        return dp[0];
        
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        return tabulation(arr);
        
    }
};