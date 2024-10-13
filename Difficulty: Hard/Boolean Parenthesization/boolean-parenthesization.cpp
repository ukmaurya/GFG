//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int i, int j , string &s , int lookTrue, vector<vector<vector<int>>> &dp){
        int mod = 1003;
        if(i>j) return 0 ;
        
        if(i==j){
            if(lookTrue==1){
                if(s[i]=='T') return 1;
                else return 0;
            }
            else{ // looking for false ie lookTrue = 0;
                if(s[i]=='F') return 1;
                else return 0;
            }
        }
        if(dp[i][j][lookTrue] != -1) return dp[i][j][lookTrue];
        // apply partition logic 
        int ans = 0;
        for(int k=i+1;k<j;k+=2 ){
            int lt = solve(i,k-1, s ,1,dp)%mod;
            int lf = solve(i,k-1,s, 0,dp)%mod;
            int rt = solve(k+1,j,s,1,dp)%mod;
            int rf = solve(k+1,j,s,0,dp)%mod;
            
            if(s[k]=='|'){
                if(lookTrue==1)
                   ans = (ans+(lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                else 
                   ans = (ans + (lf*rf)%mod)%mod;
            }
            else if(s[k]=='&'){
                if(lookTrue==1)
                   ans = (ans + (lt*rt)%mod)%mod;
                else 
                  ans = (ans+(lf*rf)%mod + (lf*rt)%mod + (lt*rf)%mod)%mod;
            }
            else if(s[k]=='^'){
                if(lookTrue==1)
                  ans = (ans+(lt*rf)%mod + (lf*rt)%mod)%mod;
                else 
                  ans=  (ans+(lt*rt)%mod + (lf*rf)%mod)%mod;
            }
        }
        return dp[i][j][lookTrue] =  ans%mod;
        
    }
   
public:
    int countWays(int N, string s){
        // int lookTrue = 1; // 0 indicates that looking for false 
        // vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        // return solve(0,N-1,S,lookTrue,dp);
        int mod = 1003;
 vector < vector < vector < int >>> dp(N, vector < vector < int >> (N, vector < int > (2, 0)));
 for (int i = 0; i <= N - 1; i++) {
      if (s[i] == 'T')
         dp[i][i][1] = 1;
       if (s[i] == 'F')
         dp[i][i][0] = 1;

   }

 for (int i = N - 1; i >= 0; i--) {
   for (int j = 0; j <= N - 1; j++) {
       if(i>=j)
        continue;

     for (int l = 0; l <= 1; l++) {
       int ans = 0;
       for (int k = i + 1; k < j; k += 2) {
         int lt = dp[i][k-1][1]%mod;  //    solve(i, k - 1, s, 1, dp) % mod;
         int lf = dp[i][k-1][0]%mod; // solve(i, k - 1, s, 0, dp) % mod;
         int rt = dp[k+1][j][1]%mod;// solve(k + 1, j, s, 1, dp) % mod;
         int rf = dp[k+1][j][0]%mod; // solve(k + 1, j, s, 0, dp) % mod;

         if (s[k] == '|') {
           if (l == 1)
             ans = (ans + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
           else
             ans = (ans + (lf * rf) % mod) % mod;
         } else if (s[k] == '&') {
           if (l == 1)
             ans = (ans + (lt * rt) % mod) % mod;
           else
             ans = (ans + (lf * rf) % mod + (lf * rt) % mod + (lt * rf) % mod) % mod;
         } else if (s[k] == '^') {
           if (l == 1)
             ans = (ans + (lt * rf) % mod + (lf * rt) % mod) % mod;
           else
             ans = (ans + (lt * rt) % mod + (lf * rf) % mod) % mod;
         }
       }
       dp[i][j][l] = ans % mod;
     }
   }
 }

 return dp[0][N - 1][1];
        
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends