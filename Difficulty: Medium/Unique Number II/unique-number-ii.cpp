class Solution {
  public:
  
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        
        int allxor = 0;
        
        for(auto num : arr){
            allxor ^= num;
        }
        
        
        unsigned int diffbit = static_cast<unsigned int>(allxor) & (~static_cast<unsigned int>(allxor)+1);
        
        int a=0,b=0;
        
        for(auto num : arr){
            if(diffbit & num){
                a ^= num;
            }
            else{
                b ^= num;
            }
        }
        
        vector<int> temp = {a,b};
        sort(temp.begin(),temp.end());
        return temp;
    }
};