// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int result = 0;
        
        for(int i=0; i<32; i++){
            int countsetbit = 0;
            for(auto num : arr){
                if(num & (1 << i)){
                    countsetbit++;
                }
            }
            
            if(countsetbit % 3 != 0){
                result |= (1 << i);
            }
        }
        
        return result;
    }
};