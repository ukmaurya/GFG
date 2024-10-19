//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> matrix) {
        // code here
        
        //  int n = matrix.size();
        // int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        int maxi =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(i==0 || j==0 ){
                    dp[i][j] = matrix[i][j];
                 }
                 else{
                       if(matrix[i][j]==0){
                         dp[i][j]=0;
                        
                       }
                       else{
                        int up = dp[i-1][j];
                        int left = dp[i][j-1];
                        int leftUpdiagonal = dp[i-1][j-1];
                        int mini = min(up , min(left , leftUpdiagonal));
                        dp[i][j] = mini+1;
                       
                       }
                        
                        
                 }
                  maxi = max(maxi , dp[i][j]);
                
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends