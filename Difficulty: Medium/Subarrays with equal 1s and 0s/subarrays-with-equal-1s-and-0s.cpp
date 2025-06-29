
class Solution {
  public:
    // Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        // Your code here
        
        long long int count = 0;
        
        // 1 0 0 1 0 1 1
        // 1 0 -1 0 -1 0 1
        
        for(int i=0; i<n; i++){
            if(arr[i] == 0) arr[i] = -1;
            
            if(i > 0)
            arr[i] += arr[i-1];
        }
        
        unordered_map<int,int> freq;
        
        for(int i=0; i<n; i++){
            
            if(arr[i] == 0) count++;
            if(freq.find(arr[i]) != freq.end()){
                count += freq[arr[i]];
            }
            
            freq[arr[i]]++;
            
        }
        
        return count;
    }
};