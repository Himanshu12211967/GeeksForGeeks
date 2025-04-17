//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool check(int i,int j,vector<vector<int>> &mat,vector<vector<bool>> &visited,int size){
        if(i >= 0 && j >= 0 && i < size && j < size && !visited[i][j] && mat[i][j] == 1)
            return true;
        return false;
    }
  
    void solve(vector<string> &ans,string temp,vector<vector<int>> &mat,int i,int j,int size,vector<vector<bool>> &visited){
        
        if(i == size-1 && j == size-1){
            ans.push_back(temp);
            return;
        }
        
        visited[i][j] = true;
        
        if(check(i-1,j,mat,visited,size)){
            temp.push_back('U');
            solve(ans,temp,mat,i-1,j,size,visited);
            temp.pop_back();
        }
        
        if(check(i+1,j,mat,visited,size)){
            temp.push_back('D');
            solve(ans,temp,mat,i+1,j,size,visited);
            temp.pop_back();
        }
        
        if(check(i,j-1,mat,visited,size)){
            temp.push_back('L');
            solve(ans,temp,mat,i,j-1,size,visited);
            temp.pop_back();
        }
        
        if(check(i,j+1,mat,visited,size)){
            temp.push_back('R');
            solve(ans,temp,mat,i,j+1,size,visited);
            temp.pop_back();
        }
        
        visited[i][j] = false;
        
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        
        vector<string> ans;
        string temp = "";
        vector<vector<bool>> visited(mat.size(),vector<bool>(mat.size(),false));
        solve(ans,temp,mat,0,0,mat.size(),visited);
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends