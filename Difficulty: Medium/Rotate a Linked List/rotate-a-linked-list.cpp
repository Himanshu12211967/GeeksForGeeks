//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    int findLength(Node *head, Node *&tail){
        int len = 0;
        for(Node *x=head; x != NULL; x=x->next){
            len++;
            tail = x;
        }
        return len;
    }
  
    Node* rotate(Node* head, int k) {
        // Your code here
        Node *tail = NULL;
        int len = findLength(head,tail);
        k = k % len;
        
        if(k == 0) return head;
        
        Node *final_head = head;
        
        while(k--){
            final_head = final_head->next;
        }
        
        tail->next = head;
        Node *temp = head;
        
        while(temp->next != final_head) temp = temp->next;
        
        temp->next = NULL;
        
        return final_head;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends