//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector<int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
        //     priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        //   pq.push({0, src}); 
        //   vector<int> dist(v, INT_MAX); 
        //   dist[src] = 0; // update dist[source]
        //   vector<vector<int>> adj[v];
        //   for(int i = 0; i < edges.size(); i++)
        //   {
              
        //           int u = edges[i][0];
        //           int v = edges[i][1];
        //           int w = edges[i][2];
                  
        //           adj[u].push_back({v,-1*w});
        //   }
          
        // //   apply dijkstra algorith
        //   while(!pq.empty())
        //   {
        //         pair<int, int> top = pq.top();
        //         pq.pop();
        //         int u = top.second;
        //         for(auto edge:adj[u])
        //         {
        //             int v = edge[0];
        //             int w = edge[1];
                    
        //             // second modification
        //             // check for dist[v] < dist[u] +  w
        //             if(dist[v] > dist[u] + w)
        //             {
        //                 // update distance of v
        //                 dist[v] = dist[u] + w;
        //                 pq.push({dist[v], v});
        //             }
        //         }
        //   }
        //   for(int i=0;i<v;i++){
        //       if(dist[i]==INT_MAX)
        //          dist[i] = INT_MIN;
        //       dist[i] = -1*dist[i];
             
               
        //   }
        //   return dist;
        
        //  approach 2 , above approach is correct but giving TLE on 2 test case
          priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
          pq.push({0, src}); 
          vector<int> dist(v, INT_MIN); // initialize dist vector with INT_MIN
          dist[src] = 0; // update dist[source]
          vector<vector<int>> adj[v];
          for(int i = 0; i < edges.size(); i++)
          {
              
                  int u = edges[i][0];
                  int v = edges[i][1];
                  int w = edges[i][2];
                  
                  adj[u].push_back({v,w}); 
          }
          
        //   apply dijkstra algorith
          while(!pq.empty())
          {
                pair<int, int> top = pq.top();
                pq.pop();
                int u = top.second;
                for(auto edge:adj[u])
                {
                    int v = edge[0];
                    int w = edge[1];
                    
                    // second modification
                    // check for dist[v] < dist[u] +  w
                    if(dist[v] < dist[u] + w)
                    {
                        // update distance of v
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
          }
          return dist;
            
            
            
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
} 
    return 0;
 
}
// } Driver Code Ends