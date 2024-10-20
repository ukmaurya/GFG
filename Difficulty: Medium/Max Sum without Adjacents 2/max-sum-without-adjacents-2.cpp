//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int solve(vector<int> &arr,int i,int cnt,vector<vector<int>> &dp){
      
      if(i>=arr.size())
      return 0;
      
      if(dp[i][cnt]!=-1)
      return dp[i][cnt];
      
      int take=0;
      
      if(cnt<2)
        take=arr[i]+solve(arr,i+1,cnt+1,dp);
      
      int notake=solve(arr,i+1,0,dp);
      
      return dp[i][cnt]=max(take,notake);
      
  }
  public:
    int findMaxSum(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(3,-1));
      return solve(arr,0,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.findMaxSum(arr);
        cout << res << endl;
        // cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends