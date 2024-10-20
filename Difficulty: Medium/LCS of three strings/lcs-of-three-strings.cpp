//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int solve(string &s1 , string &s2 ,string &s3 ,int n1,int n2, int n3,vector<vector<vector<int>>> &dp){
        if(n1<0 || n2<0 || n3<0){
            return 0 ;
        }
        if(dp[n1][n2][n3]!=-1) return dp[n1][n2][n3];
    
        if(s1[n1]==s2[n2] && s2[n2]==s3[n3]){
            return dp[n1][n2][n3] =1+solve(s1,s2,s3,n1-1,n2-1,n3-1,dp);
        }
        else{
            int l =  solve(s1,s2,s3,n1-1,n2,n3,dp);
            int m = solve(s1,s2,s3,n1,n2-1,n3,dp);
            int n = solve(s1,s2,s3,n1,n2,n3-1,dp);
            return dp[n1][n2][n3]=max(l,max(m,n));
        }
       
    }
    public:

        int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
        {
            //  int ans = 0;
            //  vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            //  ans =  solve(A,B,C ,n1-1,n2-1,n3-1,dp);
            //  return ans;
            vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    for(int k=1;k<=n3;k++){
                         if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]){
                              dp[i][j][k] =1+dp[i-1][j-1][k-1]; 
                             }
                         else{
                                int l = dp[i-1][j][k];
                                int m = dp[i][j-1][k];
                                int n = dp[i][j][k-1];
                                dp[i][j][k]=max(l,max(m,n));
                          }     
                    }
                }
            }
            
            return dp[n1][n2][n3];
        }
};



//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends