//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    Node * parentMapping( Node * root , int target , map<Node * , Node * > &parent_track){
        Node * res=NULL;
        queue<Node * >q;
        q.push(root);
        parent_track[root]=NULL;
        while(!q.empty()){
            Node * cur=q.front();
            q.pop();
            if(cur->data == target  ) res = cur;
            if(cur->left){
                parent_track[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent_track[cur->right]=cur;
                q.push(cur->right);
            }
        }
        return res;
    }
    int burntime( Node * targetNode , map<Node * , Node * > &parent_track){
        map<Node * , bool > visited;
        int ans = 0;
        queue<pair<Node* , int>>q;
        q.push({targetNode , 0});
        visited[targetNode]=true;
        while(!q.empty()){
            auto it = q.front();
            int timer = it.second;
            auto node = it.first;
            q.pop();
            ans = max(ans, timer);
            if(node->left && !visited[node->left]){
                visited[node->left]=true;
                q.push({node->left , timer+1});
            }
            if(node->right && !visited[node->right]){
                visited[node->right]=true;
                q.push({node->right , timer+1});
            }
             if(parent_track[node] && !visited[parent_track[node]]){
                visited[parent_track[node]]=true;
                q.push({parent_track[node] , timer+1});
            }
            
                
        }
        
       
        return  ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
      map<Node * , Node * > parent_track;
      Node * targetNode = parentMapping(root , target, parent_track); // create parent mapping and return target node 
      int ans = burntime(targetNode , parent_track);
      return ans;
    }
};




//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends