//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long 
class Solution {
    int mod = 1e9+7;
    ll solve(int n, vector<ll>&dp){
        if(n==1){
        
            return 0;
        }
        if(n==2)
        {
            return 1;
        }
        if(dp[n]!= -1){
            return dp[n]%mod;
        }
        // recurrene relation 
         ll ans = ((n-1)*(solve(n-2,dp)%mod + solve(n-1,dp)%mod)%mod)%mod;
         return dp[n]= ans%mod;
         
         // for first element among n  element have n- choices
        // 2 cases : let say first element are going to ith index 
        //   case1 : ith index goes to first index = solve(n-1);
        //   case2 : ith donot goes to first index => solve(n-1);
         
         
    }
  public:
    long int disarrange(int n) {
    
      vector<ll> dp(n+1, -1);
      return solve(n,dp)%mod;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.disarrange(N) << "\n";
    }
    return 0;
}
// } Driver Code Ends