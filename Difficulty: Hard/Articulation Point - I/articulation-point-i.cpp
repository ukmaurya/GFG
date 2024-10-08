//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer =1;
    private:
    void dfs(int node , int parent, vector<int>adj[], vector<int> &tin, vector<int> &low, vector<int> &vis, vector<int>&artiPoints){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int count =0;
     
        
        for(auto it: adj[node]){
            if(it==parent) 
               continue;
            if(!vis[it]){
               
                dfs(it,node , adj,tin,low,vis, artiPoints);
                
                low[node] = min(low[node],low[it]);
                if(tin[node]<=low[it] && parent!= -1 ) // for parent ==-1 , it will be edge case
                  artiPoints[node]=1;
                if(parent==-1)
                   count++;
             }
            else{
               
                  low[node] = min(low[node],tin[it]);
            }
           
           
        }
        // if intitial parent is -1 and if it has more than 1 child and all childs should be 
        //present in more than 1 components then it will be articulation points 
       if(count>1 && parent ==-1)
         artiPoints[node]=1;
        
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
       
       vector<int> tin(V);
       vector<int> low(V);
       vector<int> vis(V,0);
       vector<int> artiPoints(V , -1); 
       dfs(0,-1,adj,tin,low,vis,artiPoints);
       vector<int> ans;
       for(int i=0;i<V;i++){
           if(artiPoints[i]==1)
             ans.push_back(i);
       }
       if(ans.size()==0)
         return {-1};
       return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends