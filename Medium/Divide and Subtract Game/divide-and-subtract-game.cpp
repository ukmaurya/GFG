//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  
  bool solve(int n,vector<int> &dp){
      // Base cases
        if (n == 1) 
            return 1; 
        if (n == 0) {
            return 0; 
        }
        if(dp[n]!=-1) return dp[n];
        bool ans = false;
        for (int i = 2; i <= 5; ++i) {
            
            ans = ans || !solve(n / i, dp); // arya wining return false then only john wins
            if (ans) break;
            if (n - i >= 0) {
                ans = ans || !solve(n - i,dp);
            }
            if (ans) break; // If we already found a winning move, no need to check further
        }

        return dp[n] = ans;
   }
  public:
    string divAndSub(int N) {
        if(N==1)
         return "Arya";
       bool turn = true;
       vector<int> dp(N+1,-1);
       bool ans = solve(N,dp);
       if(ans==1)
         return "Jon";
       return "Arya";     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.divAndSub(N) << endl;
    }
    return 0;
}
// } Driver Code Ends