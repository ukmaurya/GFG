//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
     bool solve(vector<int>&vis, vector<pair<int,int>>adj[],int node, int k, int length)
    {
        if(length>=k)return true;
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i.first])
            {
                 bool check= solve(vis,adj,i.first,k,length+i.second);
                if(check)
                   return true;
                
            }
           
        }
        vis[node]=0;
        return false;
    }
public:
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
         
          vector<pair<int,int>>adj[V];
       for(int i=0; i<3*E; i+=3)
       {
           adj[a[i]].push_back({a[i+1],a[i+2]});
           adj[a[i+1]].push_back({a[i],a[i+2]});
       }
       vector<int>vis(V,0);
       bool ans =solve(vis,adj,0,k,0);
       return ans;
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends