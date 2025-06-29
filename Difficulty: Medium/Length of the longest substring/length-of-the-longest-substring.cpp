class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        int left = 0;
        int right = 0;
        int max_len = 0;
        vector<int> freq(26,0);
        int curr_dup = 0;
        
        while(right < s.length()){
            
            freq[s[right]-'a']++;
            if(freq[s[right]-'a'] > 1) curr_dup++;
            
            
            while(curr_dup > 0){
                freq[s[left]-'a']--;
                if(freq[s[left]-'a'] >= 1) curr_dup--;
                left++;
            }
            
            max_len = max(max_len,right-left+1);
            right++;
        }
        
        
        return max_len;
        
    }
};