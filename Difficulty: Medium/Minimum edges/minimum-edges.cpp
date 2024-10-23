//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
           
           vector<pair<int, int >> adj[n+1]; // adj node , edge weight
           
           // step 1: modification of the graph 
           
           for(auto it : edges){
               int u  = it[0];
               int v = it[1];
               adj[u].push_back({v,0}); // id edge present make it weight to 0
               adj[v].push_back({u,1});  // reverse edge with weight 1
           }
           
           // apply dijkstra 
           vector<int> dist(n+1, 1e9);
           vector<bool>vis(n+1, false);
           dist[src]=0;
           vis[src] = true;
           priority_queue<pair<int,int> , vector<pair<int,int>>,  greater<pair<int,int>>>pq; // since all edge weight is not  1 => cannot use queue 
           pq.push({0,src});
           while(!pq.empty()){
               int node = pq.top().second;
               int cost = pq.top().first;
               vis[node]= true;
               pq.pop();
               for(auto it: adj[node]){
                   if(vis[it.first]==true)
                     continue;
                     
                    if(dist[it.first]>cost+it.second){
                        dist[it.first] = cost + it.second;
                        pq.push({dist[it.first] , it.first});
                        
                    }
               }
           }
           
           if(dist[dst]==1e9){
               return -1;
           }
          return dist[dst];          
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends