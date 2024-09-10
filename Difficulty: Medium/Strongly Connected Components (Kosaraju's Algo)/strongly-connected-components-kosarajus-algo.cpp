//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node , vector<vector<int>>&adj,stack<int>&st,vector<int> &vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,st,vis);
            }
           
        }
        st.push(node);
    }
    void dfsrev(int node , vector<vector<int>>&adj , vector<int>&vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfsrev(it,adj,vis);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // kosaraju algorithm 
        stack<int> st; // store the edges in according to the finishing time of dfs
        vector<int> vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i])
              dfs(i, adj ,st,vis );
       }
        
        // reverse the edges
        vector<vector<int>> revAdj(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
            }
        }
        // acc to edges stored in stack aply dfs
        
        int count=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfsrev(node,revAdj , vis);
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends