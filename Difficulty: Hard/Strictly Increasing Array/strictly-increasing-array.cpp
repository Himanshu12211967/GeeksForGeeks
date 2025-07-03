class Solution {
  public:

    int min_operations(vector<int>& nums) {
        // Code here
        int LIS = 1;
        vector<int> dp(nums.size());
        dp[0] = 1;
        
        for(int i=1; i<nums.size(); i++){
            int count = 0;
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i] && (i-j) <= abs(nums[i]-nums[j])){
                    count = max(count,dp[j]);
                }
            }
            dp[i] = count+1;
            LIS = max(LIS,count+1);
        }
        
        return nums.size() - LIS;
        
    }
};