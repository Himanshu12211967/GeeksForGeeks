// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        vector<char> sorted = {'!','#','$','%','&','*','?','@','^'};
        unordered_set<char> nuts_set(nuts,nuts+n);
        unordered_set<char> bolts_set(bolts,bolts+n);
        
        int idx = 0;
        for(int i=0; i<sorted.size(); i++){
            if(nuts_set.find(sorted[i]) != nuts_set.end()){
                nuts[idx] = sorted[i];
                bolts[idx] = sorted[i];
                idx++;
            }
        }
        
    }
};