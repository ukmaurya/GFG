//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // int mod = 1e9+7;
    // int solve(int post , int col ,int count ,  int k , int n, vector<vector<vector<int>>>&dp){
    //     if(post==n){
    //         return 1;
    //     }
    //     if(dp[post][col][count]!=-1){
    //         return dp[post][col][count];
    //     }
    //     int ans = 0;
    //     for(int i=1;i<=k;i++){
    //         if(i==col && count<=1){
    //             ans= (ans + solve(post+1 ,i,count+1, k,n,dp))%mod;
    //         }
    //         else if(i != col ){
    //               ans= ( ans+solve(post+1 ,i,1, k,n,dp))%mod;
    //         }
          
    //     }
    //     return dp[post][col][count] = ans%mod;
    // }
    public:
    long long countWays(int n, int k){
    //     vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3, -1)));
    //   return solve(0,0,0,k,n,dp)%mod;
    
      // above approach is giving TLE since both n and k can be 10^5
        vector<long long>dp(n+1,-1);
      return solveMem(n,k,dp);
      
    }
    int MOD = 1e9+7;
    long long solveMem(int n,long  k,vector<long long>&dp){
        if(n==1)return k%(MOD);
        
        if(n==2)return (k*k)%(MOD);
        
        // check kar rhe hai if answer already exists
        
        if(dp[n]!=-1){
            return dp[n]%MOD;
        }
        
        long long samecolor=solveMem(n-1,k,dp)*(k-1)%(MOD);
        long long diffColor=solveMem(n-2,k,dp)*(k-1)%(MOD);
        
        return dp[n]=(samecolor+diffColor)%MOD;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends