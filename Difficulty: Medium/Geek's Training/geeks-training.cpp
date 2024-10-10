//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(int day , int prev ,vector<vector<int>>&dp, vector<vector<int>>&arr ){
        int n = arr.size();
        if(day==n){
            return 0;
        }
        
        if(dp[day][prev]!=-1){
            return dp[day][prev];
        }
        
        int ans = INT_MIN;
        for(int i=0;i<3;i++){
          if(i!= prev){
             int temp =  solve(day+1,i, dp , arr)+arr[day][i];
              ans = max(ans , temp );
          }
              
        }
        //cout<<ans<<" ";
        return dp[day][prev] = ans;
        
        
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(0,3,dp,arr); // prev= 3 means no work if -1 then it cannot be represented in dp table 
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends