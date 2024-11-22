//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{ 
    private:
      void dfs(int node , vector<int> adj[] , int c , int d , vector<int>&vis){
          vis[node]=1;
          for(auto it : adj[node]){
              if((node == c && it == d)||(node==d && it==c))
               continue;
              if( vis[it]==0 ){
                  dfs(it,adj,c,d,vis);
              }
          }
      }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
              vector<int> vis(V,0);
      
     
        dfs(c,adj,c,d,vis);
                 
        
       if(vis[d]==0)
         return true;
       return false;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends