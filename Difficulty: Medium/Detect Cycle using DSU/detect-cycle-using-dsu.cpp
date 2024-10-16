//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointset{
    vector<int>parent , size;
    
    public :
     disjointset(int n ){
        parent.resize(n+1);
        size.resize(n+1,1);
       for(int i=0;i<n+1;i++){
           parent[i]=i;
       }
        
    }
    
    void unionSize(int u, int v){
        int paru = ulti(u);
        int parv = ulti(v);
        if(paru == parv){
            return ;
        }
        if(size[paru] < size[parv]){
            parent[paru] = parent[parv];
            size[parv] += size[paru];
        }
        else{
            parent[parv] = parent[paru];
            size[paru] += size[parv];
        }
    }
    
    int ulti(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=ulti(parent[node]);
    }
};

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	     // just one thing keep in mid that , since it is undirected graph 
	     // so u cannot take a edge two time , else answer will be wrong
	     disjointset ds(V+1);
	     for(int i=0;i<V;i++){
	         for(auto it: adj[i]){
	             if(it>i){
	                 int p = i;
	                 int c = it;
	                 int parp = ds.ulti(p);
	                 int parc = ds.ulti(c);
	                 if(parp == parc){
	                     return 1;
	                 }
	                 else
	                  ds.unionSize(p,c);
	             }
	         }
	     }
	     
	     return 0;
	     
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends