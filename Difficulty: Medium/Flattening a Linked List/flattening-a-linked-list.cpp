//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    Node* merge(Node *h1 , Node* h2){
        if(h1==NULL)
           return h2;
        else if(h2==NULL)
           return h1;
        Node * temp1 =h1;
        Node * temp2=h2;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        while(temp1 && temp2){
            if(temp1->data <= temp2->data){
                prev->bottom = temp1;
                prev = temp1;
                temp1=temp1->bottom;
            }
            else{
                prev->bottom = temp2;
                prev = temp2;
                temp2 = temp2->bottom;
            }
            
        }
        while(temp1){
             prev->bottom = temp1;
             prev = temp1;
             temp1=temp1->bottom;
        }
        while(temp2){
             prev->bottom = temp2;
             prev = temp2;
             temp2 = temp2->bottom; 
        }
        return dummy->bottom;
        
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root==NULL)
          return NULL;
        Node* first = root;
        Node *sec = root->next;
        if(sec==NULL){
            return root;
        }
       while(sec){
           Node *temp = sec->next;
           Node *res = merge(first , sec);
           sec = temp;
           first = res;
          
            
       }
     return first;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends