//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	   // vector<int> dist(n,1e9);
	   // dist[0]=0;
	   // for(int i=0;i<n;i++){
	   //    for(auto it: edges){
	   //         int u = it[0];
	   //         int v = it[1];
	   //         int w = it[2];
	   //         if(dist[v]>dist[u]+w){
	   //             dist[v]=dist[u]+w;
	   //         }
	   //    }
	   // }
	
	   // for(auto it : edges){
	   //         int u = it[0];
	   //         int v = it[1];
	   //         int w = it[2];
	   //         if( dist[v]>dist[u]+w){
	   //            return 1;
	   //         }
	   // }
	   // return 0;
	    vector<int> dist(n, 1e9);
	    for(int i=0;i<n-1;i++) {
	        for(auto x: edges) {
    	        int u=x[0], v=x[1], wt=x[2];
    	        if(dist[u]+wt < dist[v]) {
    	            dist[v]=dist[u]+wt;
    	        }
    	    }
	    }
	    for(auto x: edges) {
	        int u=x[0], v=x[1], wt=x[2];
	        if(dist[u]+wt < dist[v]) {
	            return 1;
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends