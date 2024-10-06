//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long 
class Solution{
    ll solve(int i , int j , int arr[] , bool turn,vector<vector<ll>>&dp){
     
       if(i>j)
        return 0;
        if(dp[i][j]!=-1)
         return dp[i][j];
    
      ll ans = 0;
    
       if(turn==true){
         ll first = solve(i+1 , j,arr , false,dp)+arr[i];
         ll sec = solve(i,j-1,arr,false,dp)+arr[j];
           ans = max(first , sec);
       }
       else{
         ll first = solve(i+1 , j,arr , true,dp);
         ll sec = solve(i,j-1,arr,true,dp );
          ans = min(first , sec);
       }
     return dp[i][j]=ans ;
     
}
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
         vector<vector<ll>>dp(n,vector<ll>(n,-1));
         return solve(0,n-1,arr,true,dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends