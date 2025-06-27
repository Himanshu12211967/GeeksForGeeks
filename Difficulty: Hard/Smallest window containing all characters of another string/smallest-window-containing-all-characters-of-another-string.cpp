class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        // Your code here
        
        int left = 0;
        int right = 0;
        
        unordered_map<char,int> m;
        int curr_req = 0;
        
        for(auto ch : s2){
            m[ch]++;
            curr_req++;
        }
        
        int min_len = INT_MAX;
        int start = 0;
        
        
        while(right < s1.length()){
            
            if(m.find(s1[right]) != m.end()){
                m[s1[right]]--;
                if(m[s1[right]] >= 0) curr_req--;
            }
            
            while(curr_req == 0){
                
                if(min_len > right-left+1){
                    min_len = min(min_len,right-left+1);
                    start = left;
                }
                
                if(m.find(s1[left]) != m.end()){
                    m[s1[left]]++;
                    if(m[s1[left]] > 0) curr_req++;
                }
                
                left++;
            }
            
            right++;
            
        }
        
        if(min_len == INT_MAX) return "";
        string ans = s1.substr(start,min_len);
        return ans;
        
    }
};