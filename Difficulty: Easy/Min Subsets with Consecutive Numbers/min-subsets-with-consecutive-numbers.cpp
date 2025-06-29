class Solution {
  public:
    int numOfSubset(vector<int> &arr) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        
        int count = 0;
        int i = 0;
        int j = 1;
        
        
        while(j < arr.size()){
            
            if(arr[i]+1 == arr[j]){
                i++;
                j++;
            }
            else{
                count++;
                i=j;
                j=i+1;
            }
            
        }
        
        return count+1;
    }
};