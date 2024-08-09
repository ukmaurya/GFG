//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(int step , vector<int>&arr , int &k,  vector<int>&dp){
        int n = arr.size();
        if(step==n-1){
            return 0;
        }
        if(dp[step]!=-1){
            return dp[step];
        }
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
            if(step+i<=n-1)
               ans=min(ans, solve(step+i ,arr , k,dp )+abs(arr[step+i]-arr[step]));
        }
        return dp[step]=ans;
    }
  public:
    int minimizeCost(vector<int>& arr, int& k) {
          int n = arr.size();
          vector<int> dp(n, -1);
          int ans = solve(0, arr, k ,dp);
          return ans;
          
       
       
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends