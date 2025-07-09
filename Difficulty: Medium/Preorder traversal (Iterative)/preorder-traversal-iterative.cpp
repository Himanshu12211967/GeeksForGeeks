// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
  
    vector<int> preOrder(Node* root) {
        // code here
        
        vector<int> ans;
        
        while(root){
            
            if(root->left == NULL){
                ans.push_back(root->data);
                root = root->right;
            }
            else{
                Node *temp = root->left;
                while(temp->right != root && temp->right != NULL){
                    temp = temp->right;
                }
                
                if(temp->right == NULL){
                    ans.push_back(root->data);
                    temp->right = root;
                    root = root->left;
                }
                else{
                    temp->right = NULL;
                    root = root->right;
                }
            }
            
        }
        
        return ans;
        
    }
};