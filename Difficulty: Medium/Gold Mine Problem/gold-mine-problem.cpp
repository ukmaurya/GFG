//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int row,int col, vector<vector<int>>&M,vector<vector<int>>&dp){
       
        int n = M.size();
        int m = M[0].size();
        if(col==m-1)
           return M[row][col];
        
        if(dp[row][col]!=-1)
          return dp[row][col];
        int diaUp = INT_MIN;
        int right = INT_MIN;
        int diaDown = INT_MIN;
        if(row-1 >=0 && col+1<m)
           diaUp = solve(row-1,col+1, M,dp)+M[row][col];
        if(col+1 <m)
           right = solve(row , col+1 , M,dp) + M[row][col];
        if(row+1<n && col+1 < m ){
            diaDown = solve(row+1 , col+1 , M,dp) + M[row][col];
        } 
        
        return dp[row][col] = max(diaUp , max(right , diaDown));
        
        
    }
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
         int ans = INT_MIN;
         vector<vector<int>>dp(n, vector<int>(m,-1));
         for(int i=0;i<n;i++){
             int res  = solve(i,0, M,dp); // SINCE COL WILL ALWAYS CHANGES 
             ans = max(ans , res);
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends