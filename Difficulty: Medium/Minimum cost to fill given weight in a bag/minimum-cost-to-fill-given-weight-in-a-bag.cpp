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
    int getans(int n,int w,vector<int>&cost,int index,vector<vector<int>>&dp){
        if(w == 0) return 0;
        if(index > n) return INT_MAX;
        if(dp[index][w] != -1) return dp[index][w];
        int include = INT_MAX;
        if(index <= w && cost[index-1] != -1){
            include = getans(n,w-index,cost,index,dp);
            if(include != INT_MAX){
                include += cost[index-1];
            }
        }
        int exclude = getans(n,w,cost,index+1,dp);
        return dp[index][w] = min(include,exclude);
    }
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
           
            vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        int ans = getans(n,w,cost,1,dp);
        return ans == INT_MAX ? -1 : ans;
              
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends