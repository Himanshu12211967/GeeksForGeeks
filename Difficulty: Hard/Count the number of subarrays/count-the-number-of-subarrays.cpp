// User function Template for C++
class Solution {
  public:
    long long countSubarray(int N, vector<int> A, long long L, long long R) {
        // code here
        int left = 0;
        int right = 0;
        long long count = 0;
        long long sum = 0;
        
        while(right < N){
            
            sum += A[right];
            
            while(sum > R){
                sum -= A[left++];
            }
            
            count += right-left+1;
            right++;
        }
        
        
        left = 0;
        right = 0;
        sum = 0;
        
        
        while(right < N){
            
            sum += A[right];
            
            while(sum >= L && left <= right){
                sum -= A[left++];
            }
            
            count -= right - left + 1;
            right++;
        }
        
        return count;
    }
};