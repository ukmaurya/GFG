//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here

        int n = arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1, false));
        // initialisation
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
           
        }
        // for(int j=0;j<=sum;j++){
        //      if(j==arr[n-1]){
        //         dp[n-1][j]=true;
        //     }
          
        // }
        for(int i=n-1 ;i>=0;i--){
            for(int j=0;j<=sum;j++){
                  bool pick= false;
                  bool ntpick = false;
                  if(arr[i]<=j)
                      pick = dp[i+1][j-arr[i]];
                   ntpick = dp[i+1][j];  
                   dp[i][j] = pick||ntpick;
            }
        }
        
        
        return dp[0][sum];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends