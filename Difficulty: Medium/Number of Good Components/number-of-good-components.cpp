//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    void solve(int node , vector<int>adj[] , vector<int>&vis , int &vertex , int &edge){
        vis[node]=1;
        vertex++;
        for(auto it : adj[node]){
             edge++;
            if(!vis[it]){
                 
                solve(it , adj, vis, vertex, edge);
            }
        }
        
    }
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
         
         int n = edges.size();
         vector<int> adj[v+1];
         for(int i=0;i<n;i++){
             int u  = edges[i][0];
             int v = edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
         
         vector<int> vis(v+1,0);
         int ans = 0;
         for(int i=1;i<=v;i++){
             if(vis[i]==1)
              continue;
             int vertex =0;
             int edge = 0;
           
                 solve(i,adj,vis,vertex , edge);
             
             if((vertex*vertex-vertex)==edge)
               ans++;
             
             
         }
         return ans;
         
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends