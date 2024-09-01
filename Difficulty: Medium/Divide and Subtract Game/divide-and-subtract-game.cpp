//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    bool solve(int n , bool turn,  vector<vector<int>> &dp){
        if(n==0){
            if(turn == true){
                return false;
            }
            else{
                return true;
            }
        }
        else if(n==1){
            if(turn == true){
                return true;
            }
            else 
             return false;
        }
        if(dp[n][turn]!=-1){
            return dp[n][turn];
        }
        
        // explore all possibilities
        if(turn == true){
              bool ans = false;
          for(int i=2;i<=5;i++){
            ans = ans||solve(n-i,!turn,dp);
            ans = ans||solve(floor(n*1.0/i) , !turn,dp);
           }
           return dp[n][turn]=ans;
        }
        else{
              bool ans = true;
           for(int i=2;i<=5;i++){
            ans = ans&&solve(n-i,!turn,dp);
            ans = ans&&solve(floor(n*1.0/i) , !turn,dp);
        }
        return dp[n][turn]=ans;
        }
        return false;
    }
  
  public:
    string divAndSub(int N) {
        int n = N;
         vector<vector<int>> dp(N+1,vector<int>(2,-1));
        if(n==1 || n==0){
            return "Arya";
        }
       
       int ans = solve(N,true, dp);
       if(ans==true){
           return "Jon";
       }
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