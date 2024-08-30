//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   private:
   int solve(int arr[]  , int idx , int s1 , int s2,vector<vector<vector<int>>>&dp){
       if(idx < 0){
           return abs(s1-s2);
       }
       if(dp[idx][s1][s2]!=-1)
         return dp[idx][s1][s2];
       int left = solve(arr , idx-1 ,s1+arr[idx] , s2,dp );
       int right = solve(arr , idx-1 , s1 , s2+arr[idx],dp);
       return dp[idx][s1][s2] = min(left , right);
   }
  public:
	int minDifference(int arr[], int n)  { 
	  /* int tot =0;
	    if(n==1) return arr[0];
	   for(int i=0;i<n;i++)
	    tot+= arr[i];
	   vector<vector<vector<int>>>dp(n , vector<vector<int>>(tot+1 , vector<int>(tot+1 , -1)));
	   return solve(arr , n-1 , 0 ,0,dp); */
	   
	  // above approch will give memory limit exceeded on some cases
	  
	    int tot =0;
	   for(int i=0;i<n;i++)
	       tot+= arr[i];
	  // tot = tot/2;   
	   vector<vector<bool>>dp(n+1, vector<bool>(tot+1 , false));
	   for(int i=0;i<n;i++){
	       dp[i][0] = true;
	   }
	   for(int sum=0;sum<=tot;sum++){
	       if(sum==arr[n-1])
	         dp[n-1][sum]=true;
	   }
	   for(int i=n-2;i>=0;i--){
	       for(int sum = 0;sum<=tot;sum++){
	           bool take = false;
	           bool ntake = false;
	           if(arr[i]<=sum)
	             take = dp[i+1][sum-arr[i]];
	           ntake = dp[i+1][sum];
	           dp[i][sum] = take||ntake;
	       }
	   }
	   
	   int maxi = INT_MAX;
	   for(int sum =0;sum<=tot;sum++){
	       if(dp[0][sum]==true){
	           maxi = min(maxi , abs(tot-2*sum));
	       }
	   }
	   return maxi;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends