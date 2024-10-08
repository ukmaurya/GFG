//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool solve(int node, vector<int> adj[] , vector<bool>&vis , vector<bool>&ispath ){
        vis[node] = true;
        ispath[node]=true;
        for(auto it: adj[node]){
            if(vis[it] && ispath[it]){
                return true;
            }
            else if(!vis[it] ){
                // return solve(it,adj , vis, ispath) is wrong as if fun return false 
                //it will not explore othe adj node 
                 if(solve(it,adj , vis, ispath)==true){
                     return true;
                 }
                 
            }
           
        }
        ispath[node]= false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> ispath(V, false);
        int ans = false;
        for(int i=0;i<V;i++){
            ans = ans ||  solve(i,adj , vis, ispath);
        }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends