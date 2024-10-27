//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int solve(int city , int mask , vector<vector<int>>&cost,vector<vector<int>>&dp){
        int n = cost.size();
        if(mask==(1<<n)-1){
            return cost[city][0]; // move to 0 th city
        }
        if(dp[city][mask]!=-1)
          return dp[city][mask];
        
        int ans = INT_MAX;
        for(int k=0;k<n;k++){
            if( k!= city && !(mask&(1<<k))){
                ans = min(ans ,solve(k,mask|(1<<k) , cost,dp)+cost[city][k]);
            }
        }
        return dp[city][mask] =  ans;
    }
public:
int total_cost(vector<vector<int>>cost){
    int n = cost.size();
    vector<vector<int>>dp(n,vector<int>((1<<n),-1));
    int ans = solve(0,1,cost,dp);
    return ans;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends