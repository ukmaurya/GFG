//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int solve(int index , int mask , vector<vector<int>>&cost,vector<vector<int>>&dp){
        int n =cost.size();
        if( mask == ((1<<n)-1)){
            return cost[index][0];
        }
        if(dp[index][mask]!=-1)
          return dp[index][mask];
        // 
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(i==index)
              continue;
            if((mask&(1<<i))==0){
                int newMask = mask|(1<<i);
                ans = min(ans , solve(i,newMask,cost,dp)+cost[index][i]);
                // no need to unset the mask as we send newMask not mask 
            }
        }
        return dp[index][mask]=ans;
    }
public:
int total_cost(vector<vector<int>>cost){
       // applying the bit mask dp 
         int mask = 0;
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
	}
	return 0;
}
// } Driver Code Ends