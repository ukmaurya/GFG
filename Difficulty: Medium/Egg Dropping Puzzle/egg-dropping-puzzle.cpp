//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   private:
    int dp[201][201];
    int solve(int e , int k ){
        // base case 
         if(e==1) return k; 
         if(k==0 || k== 1) return k;
         if(dp[e][k] !=-1) return dp[e][k];
         int ans = INT_MAX;
         for(int i= 1;i<=k;i++){ // for exach floor we are checking worst case possible 
          // by checking both cases , egge break and not break 
             int temp= 1+ max(solve(e-1,i-1) , solve(e,k-i));// max since we have to find ans in worst case 
             ans= min(ans, temp); // min since we have to find minimum no of attempt 
         }
         return dp[e][k]= ans;
    }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends