//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long 
class Solution{
//     ll solve(int i , int j , int arr[] , bool turn,vector<vector<ll>>&dp){
     
//       if(i>j)
//         return 0;
//         if(dp[i][j]!=-1)
//          return dp[i][j];
    
//       ll ans = 0;
    
//       if(turn==true){
//          ll first = solve(i+1 , j,arr , false,dp)+arr[i];
//          ll sec = solve(i,j-1,arr,false,dp)+arr[j];
//           ans = max(first , sec);
//       }
//       else{
//          ll first = solve(i+1 , j,arr , true,dp);
//          ll sec = solve(i,j-1,arr,true,dp );
//           ans = min(first , sec);
//       }
//      return dp[i][j]=ans ;
     
// }
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
        //  vector<vector<ll>>dp(n,vector<ll>(n,-1));
        //  return solve(0,n-1,arr,true,dp);
        
        
        // above is by using the tur variable 
        
        
        //approach 2 : without using the turn variable 
        
        // concept is same , we try to maximise our score, while opponent want to 
         // maximise theor score means minimise our score
        vector<vector<ll>>dp(n,vector<ll>(n,-1));
        return solve(0,n-1,n, arr,dp);   
      }
    int solve(int i , int j , int n  ,int arr[] ,vector<vector<ll>>&dp ){
        if(i==j){
            return arr[i];
        }
        if(i>j){
            return 0;
        }
          if(dp[i][j]!=-1)
           return dp[i][j];
        
        // aur apponents wants to decrease our score 
        int appo1 = min( solve(i+2 ,j , n , arr,dp )  , solve(i+1 , j-1 , n , arr,dp)); // a[i] chosen by us 
        int appo2 = min(solve(i,j-2,n,arr,dp) , solve(i+1 , j-1,n,arr,dp));
        
        // our choice 
        int choice1 = arr[i]+appo1; // choose a[i]
        int choice2 = arr[j]+appo2;  // choose a[j]
        return dp[i][j] = max(choice1 , choice2);
        
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