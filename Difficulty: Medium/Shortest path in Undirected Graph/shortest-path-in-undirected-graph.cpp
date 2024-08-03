//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
         
         // since unit weight => we can use simple queue also , instead of priority queue
         
         vector<int> adj[N];
         for(int i=0;i<M;i++){
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
         }
         vector<int> dist(N,INT_MAX);
        // vector<int> vis(N,0);
         queue<pair<int, int >> q; // dist , node
         dist[src]=0;
         q.push({0, src});
         while(!q.empty()){
             int node = q.front().second;
             int d = q.front().first;
             q.pop();
             // relaxation of edges 
             for(auto it: adj[node]){
                 if(dist[it] > dist[node]+1){
                     dist[it] = dist[node]+1;
                     q.push({dist[it],it});
                 }
             }
         }
         for(int i=0;i<N;i++){
             if(dist[i]==INT_MAX){
                 dist[i]=-1;
             }
         }
         
         return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends