/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
  
    void solve(Node *root, vector<int> &ans){
        
        if(root == NULL){
            ans.push_back(-1);
            return;
        }
        
        ans.push_back(root->data);
        solve(root->left,ans);
        solve(root->right,ans);
        
    }
    
    Node *solve2(vector<int> &ans,int &i){
        
        if(i >= ans.size() || ans[i] == -1){
            i++;
            return NULL;
        }
        
        Node *root = new Node(ans[i++]);
        root->left = solve2(ans,i);
        root->right = solve2(ans,i);
        return root;
        
    }
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> ans;
        solve(root,ans);
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        
        // Your code here
        int i = 0;
        return solve2(arr,i);
    }
};