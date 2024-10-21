//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    int mod = 1e9+7;
    private:
    int solve(int n,vector<int> &dp){
        if(n==1 || n==2)
          return n;
        if(dp[n]!= -1)
          return dp[n];
        int remainSingle = solve(n-1,dp)%mod;
        int makePair = (solve(n-2,dp)*1LL*(n-1))%mod; // a ele make pair with n-1 elements
       // since we want only count so make call for one element and multiply with req number 
        return dp[n] = (remainSingle+makePair)%mod;
        
    }
    
public:
    int countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1, -1);
        return solve(n,dp);
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends