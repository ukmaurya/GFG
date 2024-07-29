//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    bool isSafe(int u, vector<int>&color , bool graph[101][101] ){
        for(int index = 0;index<=101;index++){
            if(index==u)
             continue;
            if(graph[u][index]==true && color[index]==color[u]){
                return false;
            }
        }
        return true;
        
    }
    bool solve(int u ,int m , int n , bool graph[101][101] , vector<int>&color){
           if(u==n){
               return true;
           }
          for(int k=1;k<=m;k++){
               color[u]=k;
               if(isSafe(u,color,graph)){
                  
                   if(solve(u+1,m,n,graph ,color) == true){
                        return true;
                  }
                 
               }
               color[u]=-1;  
                   
          }
            
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<int> color(n,-1);
        
        return solve(0,m,n,graph , color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends