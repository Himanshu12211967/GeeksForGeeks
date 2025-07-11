/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    string solve(Node *root, int &count){
        
        if(root == NULL) return "fullfilled";
        if(root->left == NULL && root->right == NULL){
            return "wants vaccine";
        }
        
        string left = solve(root->left,count);
        string right = solve(root->right,count);
        
    
        if(left == "wants vaccine" || right == "wants vaccine"){
            count++;
            return "Given";
        }
        if(left == "Given" || right == "Given"){
            return "fullfilled";
        }
        return "wants vaccine";
        
    }
  
    int supplyVaccine(Node* root) {
        // Your code here
        int count = 0;
        if(solve(root,count) == "wants vaccine") count++;
        return count;
    }
};