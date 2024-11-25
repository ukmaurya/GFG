//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
    int solve(int i , string&s , int j , string &t, vector<vector<int>>&dp){
        if(i<0 || j<0)
          return 0;
        if(dp[i][j]!= -1)
          return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = 1+solve(i-1,s,j-1,t,dp);
        }  
        else{
            return dp[i][j]=max(solve(i-1,s,j,t,dp) , solve(i,s,j-1,t,dp));
        }
    }
  public:
    // Function to find the length of the longest common subsequence in two strings.
    int getLCSLength(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
         return solve(n-1, s1 , m-1,s2,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.getLCSLength(s1, s2) << endl; // Call the getLCSLength function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends