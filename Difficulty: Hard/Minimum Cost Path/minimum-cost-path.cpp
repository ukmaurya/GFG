//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
 {    private:
//       int solve(int i ,int j, vector<vector<int>>&dp, vector<vector<int>>& grid,vector<vector<int>>&vis){
//               int a = grid.size();
//               int b = grid[0].size();
             
//              if(i>=a || j>=b|| i<0 || j<0 ) return 1e9;
//              if(i==0 && j==0) return grid[0][0];
//              if(dp[i][j]!=-1) return dp[i][j];
//              int ans1=1e9;
//              if(i-1 >= 0 && vis[i-1][j] !=1 ){
//                   vis[i-1][j]=1;
//                 ans1 = solve(i-1 ,j,dp,grid,vis)+grid[i][j];
//                 vis[i-1][j]=0;
//              }
//              int ans2 = 1e9;
//              if(j-1 >= 0 && vis[i][j-1]!= 1 ){
//                   vis[i][j-1]=1;
//                   ans2 = solve(i,j-1,dp,grid,vis)+grid[i][j];
//                  vis[i][j-1]=0;
//              }
//              int ans3 =1e9 ; 
//              if(j+1 < b && vis[i][j+1] !=1 ){
//                   vis[i][j+1] =1;
//                 ans3= solve(i,j+1,dp,grid,vis)+grid[i][j];
//                  vis[i][j+1] =0;
    
//              int ans4 =1e9;    
//              if(i+1 < a && vis[i+1][j]!=1 ){
//                  vis[i+1][j]=1;
//               ans4 = solve(i+1,j,dp,grid,vis)+grid[i][j];
//                  vis[i+1][j]=0;
//              }
//              return dp[i][j] = min(ans1,min(ans2,min(ans3,ans4)));    
             
//       } 
// it will fail as it will give fail as while backtraking visited is unmarked but dp array is not unmarked i twill return old value 
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	public: 
    int minimumCostPath(vector<vector<int>>& grid) {
    // {    int a = grid.size();
    //      int b = grid[0].size();
    //      vector<vector<int>> dp(a,vector<int>(b,-1));
    //      vector<vector<int>> vis(a,vector<int>(b,0));
    //      vis[a-1][b-1]=1;
    //      return solve(a-1,b-1,dp, grid,vis );
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
           
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
           
            if(row == n-1 && col == n-1) return cost;
           
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(ncol >= 0 && ncol < n && nrow >= 0 && nrow < n && dist[nrow][ncol] > cost + grid[nrow][ncol]) {
                    dist[nrow][ncol] = cost + grid[nrow][ncol];
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
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
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends