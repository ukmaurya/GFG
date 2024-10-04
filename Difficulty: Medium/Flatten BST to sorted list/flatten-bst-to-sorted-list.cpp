//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *newNode(int key)
{
    Node *node = new Node(key);
    return node;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void printList(Node *head)
{
    if(head){
        while (head)
        {
            if(head->left)
                cout<<"-1 ";
            cout << head->data << " ";
            head = head->right;
        }
        cout << "\n";
    }
    else{
        cout << "Empty Tree!!";
    }
}


// } Driver Code Ends
//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
   
public:
    Node *flattenBST(Node *root)
    {
        // iterative 
       
       // Base case: if the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    Node *cur = root;
    Node *head = NULL; // To track the new head of the flattened tree
    Node *prev = NULL; // To track the previously processed node
    
    while (cur) {
        // If the current node has a left child
        if (cur->left) {
            // Find the rightmost node in the left subtree
            Node *temp = cur->left;
            while (temp->right) {
                temp = temp->right;
            }
            
            // Re-link the rightmost node to the current node's right subtree
            temp->right = cur;
            
            // Move the left child to the right and set the left to NULL
            Node *leftSubtree = cur->left;
            cur->left = NULL;
            cur = leftSubtree; // Move to the left child, which is now the current node
        } else {
            // If there's no left child, we're processing the current node
            if (head == NULL) {
                head = cur; // Set head if this is the first node (smallest element)
            }

            if (prev != NULL) {
                prev->right = cur; // Connect the previous node to the current node
            }
            prev = cur; // Update previous node
            
            // Move to the right child
            cur = cur->right;
        }
    }
    
    return head; // Return the new head of the flattened tree
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        auto ans = ob.flattenBST(root);
        printList(ans);
    }
    return 0;
}


// } Driver Code Ends