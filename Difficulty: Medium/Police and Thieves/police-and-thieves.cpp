//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int catchThieves(vector<char> &arr, int k) {
        
        // Code here
        
        vector<int> police;
        vector<int> theives;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 'P') police.push_back(i);
            else theives.push_back(i);
        }
        
        int i = 0;
        int j = 0;
        int caught = 0;
        
        while(i < police.size() && j < theives.size()){
            
            if(abs(police[i]-theives[j]) <= k){
                caught++;
                i++;
                j++;
            }
            else if(police[i] < theives[j]){
                i++;
            }
            else{
                j++;
            }
            
        }
        
        return caught;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<char> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        char ch;
        while (ss >> ch) {
            arr.push_back(ch);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        cout << obj.catchThieves(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends