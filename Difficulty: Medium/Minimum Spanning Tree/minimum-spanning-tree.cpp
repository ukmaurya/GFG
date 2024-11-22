//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> minh;
        vector<int> vis(V,0); // helps to avoid cycles
        minh.push({0,0}); // weight, node . we are not keeping parent since we need only sum not whole MST
        int sum=0;
       // vis[0]=1; 
        while(!minh.empty()){
            auto it= minh.top();
            minh.pop();
            int node = it.second;
            int wt= it.first;
            if(vis[node]==1)
              continue;
            // add to the mst
            vis[node]=1;
            sum+=wt;
            // now find the adjacent nodes 
            for(auto it : adj[node]){
                int adjnode = it[0];
                int edgewt = it[1];
                if(!vis[adjnode]){
                     // vis[adjnode]=1; // it is not bfs , workout with example 
                      minh.push({edgewt,adjnode});
                      
                }
                 
            }
        }
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends