//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void components(int node ,vector<bool>&vis ,  vector<int>adj[]){
        vis[node]= true;
        for(auto it: adj[node]){
            if(vis[it]==false){
                components(it, vis,adj);
            }
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
          int c1 = 0;
          vector<bool> vis(V,false);
          for(int i=0;i<V;i++){
              if(vis[i]==false){
                  c1++;
                  components(i ,vis, adj);
              }
          }
         
         vector<int> newAdj[V];
         for(int i=0;i<V;i++){
             vis[i]=false;
             for(auto it:adj[i]){
                 if((i==c && it==d)||(i==d && it==c))
                  continue;
                newAdj[i].push_back(it);
                newAdj[it].push_back(i);
             }
         }
         int c2 = 0;
          for(int i=0;i<V;i++){
              if(vis[i]==false){
                  c2++;
                  components(i ,vis, newAdj);
              }
          }
         if(c1==c2){
             return false;
         }
         return true;
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
    }

    return 0;
}


// } Driver Code Ends