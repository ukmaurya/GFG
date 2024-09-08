//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
      /*  int n = arr.size();
          int mod =1e5;
          queue<pair<int,int>> q;
          q.push({0,start});
          while(!q.empty()){
              auto temp = q.front();
              int node = temp.second;
              int step = temp.first;
              if(node==end){
                  return step;
              }
              else if(node>end){
                  continue;
              }
              q.pop();
              for(int i=0;i<n;i++){
                  if((arr[i]*node)%mod == end)
                    return step+1;
                  q.push({step+1 , (arr[i]*node)%mod});
              }
          }
          return -1; */
          // above was bfs logic giving TLE
          int mod = 1e5;
        vector<int> dist(1e5 , INT_MAX);
        dist[start]=0;
        queue<pair<int,int>> q; // dist , node 
        q.push({0,start});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.second%mod;
             
            int nodedist = it.first%mod;
          
            for(int i=0;i<arr.size();i++){
                int adjNode = (node*arr[i])%mod;
               
                if( dist[adjNode] > nodedist+1){
                    dist[adjNode] = (nodedist+1)%mod;
                    q.push({dist[adjNode] , adjNode});
                }
            }
        }
        
        if(dist[end]==INT_MAX)
          return -1;
        else 
          return dist[end]%mod;
          
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends