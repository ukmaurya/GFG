//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
     int solve(vector<int> &arr,int i,int prev,vector<vector<int>> &dp){
      
      if(i>=arr.size())
      return 0;
      
      if(dp[i][prev+1]!=-1)
      return dp[i][prev+1];
      
      int take=0;
      
      if(prev==-1 || abs(arr[i]-arr[prev])==1 )
        take=1+solve(arr,i+1,i,dp);
      
      int notake=solve(arr,i+1,prev,dp);
      
      return dp[i][prev+1]=max(take,notake);
      
  }
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         return solve(a,0,-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends