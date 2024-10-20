//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution
{   private:
     int solve(int n , int m , string s1 , string s2,vector<vector<int>> &dp){
          
          if(n==0 || m==0) return 0;
          if(dp[n][m]!=-1) return dp[n][m];
          if(s1[n-1] == s2[m-1])
           {
             return dp[n][m]=1+solve(n-1,m-1,s1,s2,dp);
           }
         else
           return dp[n][m]=max( solve(n-1,m,s1,s2,dp) , solve(n,m-1,s1,s2,dp) );
     }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {    
         //  after shifting of origin 
        //   vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
        //   // initialisation 
        //   for(int i=0;i<n+1;i++){
        //       for(int j=0;j<m+1;j++){
        //           if(i==0 || j==0 )
        //             dp[i][j] = 0;
        //       }
        //   }
        //   // step 2
        //   for(int i=1;i<=n;i++){
        //       for(int j=1;j<=m;j++){
                  
        //           if(s1[i-1] == s2[j-1])
        //               dp[i][j]=1+dp[i-1][j-1];
        //           else
        //               dp[i][j]=max( dp[i-1][j] , dp[i][j-1] );
        //       }
        //   }
        //   return dp[n][m];
        
        // space optimisation 
        vector<int> up(m+1 ,0);
        for(int i=1;i<=n;i++){
            vector<int>cur(m+1,0);
            for(int j=1;j<=m;j++){
                  
                  if(s1[i-1] == s2[j-1])
                      cur[j]=1+up[j-1];
                  else
                      cur[j]=max( up[j] , cur[j-1] );
              }
              up = cur;
          }
        return up[m];
    }
};




//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends