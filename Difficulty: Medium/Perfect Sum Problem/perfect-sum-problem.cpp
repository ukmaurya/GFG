//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private :
    int solve(int i, int arr[], int n , int sum , vector<vector<int >>&dp){
        int mod = 1e9+7;
         // if(sum==0) {return 1} we will remove this base case as we need to go in deep 
         // till index 0 if we return from there then we may left out since 0's are there 
          
        if(i==n-1){
            if(sum==0 && arr[n-1]==0) // case 1 
              return 2;
            if(sum==0 || arr[n-1] == sum ) return 1; // case 2 
            else  // case 3
            return 0;
        }  
        if( dp[i][sum]!=-1 ) return dp[i][sum];
        int ex = 0;
          ex = solve(i+1,arr, n , sum,dp);
        int in = 0;
        if(arr[i]<= sum ) // take care in case when elements are zeroes  
            in = solve(i+1,arr,n,sum-arr[i] , dp );
        
        return dp[i][sum] = (in + ex )%mod;    
        
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	      int mod = 1e9+7;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int ans = solve(0 , arr, n, sum ,dp ); // number of subset with sum considering n-1 indexes 
        return ans;
	    
	   
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends