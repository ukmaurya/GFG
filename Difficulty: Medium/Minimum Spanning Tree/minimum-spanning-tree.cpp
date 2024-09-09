//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointset{
    vector<int> parent , size;
    public: 
      disjointset(int n ){
          parent.resize(n);
          size.resize(n,1);
          for(int i=0;i<n;i++){
              parent[i]=i;
          }
      }
      int ultiPar(int node){
          if(parent[node]==node){
              return node;
          }
          return parent[node]=ultiPar(parent[node]);
      }
      void unionSize(int u , int v){
          int x = ultiPar(u);
          int y = ultiPar(v);
          if(x==y){
              return ;
          }
          if(size[x]<=size[y]){
              parent[x] = parent[y];
              size[y]+= size[x];
          }
          else{
              parent[y] = parent[x];
              size[x] += size[y];
          }
      }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         // using krushkal algorithm 
         disjointset ds(V+1);
         
         priority_queue<pair<int, pair<int,int >> , vector<pair<int, pair<int,int >> > , greater<pair<int, pair<int,int >> >>pq;
         for(int i=0;i<V;i++){
              for(auto it : adj[i]){
                pq.push({it[1],{i ,it[0]}});
               }
         }
         int sum=0;
         while(!pq.empty()){
             auto temp = pq.top();
             pq.pop();
             int u = temp.second.first;
             int v = temp.second.second;
             int cost = temp.first;
             if(ds.ultiPar(u)!= ds.ultiPar(v)){
                 ds.unionSize(u,v);
                 sum += cost;
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
    }

    return 0;
}


// } Driver Code Ends