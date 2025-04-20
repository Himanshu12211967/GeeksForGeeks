//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends

// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
  
    // 1 - prev
    // 4 - 3 - 2 - null
    // 5 - curr
    // 4 - prev
  
    Node *reverse(Node *head, int k){
        
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        
        while(curr != NULL && k != 0){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        
        head->next = curr;
        return prev;
        
    }
  
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        
        Node *temp = head;
        Node *prev = NULL;
        int k = a;
        
        while(--k){
            prev = temp;
            temp = temp->next;
        }
        
        if(prev == NULL){
            return reverse(temp,b-a+1);
        }
        
        prev->next = reverse(temp,b-a+1);
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int a = arr[0], b = arr[1];

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        if (arr2.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr2[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr2.size(); ++i) {
            data = arr2[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node* newhead = ob.reverseBetween(a, b, head);
        printList(newhead);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends