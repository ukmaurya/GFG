//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve( int price[] , int n , int len,vector<int> &dp ){
        if(len<=0){
            return 0;
        }
        if( dp[len]!= -1 )
          return dp[len];
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i+1<=len)
               ans = max(ans , solve( price , n , len-(i+1),dp)+price[i] );
        }
        return dp[len]=ans;
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,-1);
        int ans = solve(price , n ,n,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends