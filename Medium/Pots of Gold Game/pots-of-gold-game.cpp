//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private: 
    int solve(int i, int j , vector<int>&A, vector<vector<int>>&dp ){
        if(i>j)
           return 0;
       
       if(dp[i][j]!= -1)
         return dp[i][j];
       
        int left  =  A[i]+min(solve(i+2,j,A,dp), solve(i+1,j-1,A,dp));
        int right =  A[j]+min(solve(i+1,j-1,A,dp) , solve(i,j-2 ,A,dp));
        return dp[i][j]= max(left , right);
      }
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>>dp(n,vector<int>(n,-1));
	    return solve(0,n-1,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}

// } Driver Code Ends