//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
   /* int solve(string &s1 , string &s2 , int prev1 , int prev2 , int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        int take =0;
        if(s1[i]==s2[j] &&((prev1==-1||prev1-1==i )&&(prev2==-1||prev2-1==j) )){
           return take = 1+solve(s1,s2,i,j,i-1,j-1);
        }
        else if(s1[i]!=s2[j]){
           return  take = max(solve(s1,s2,prev1,prev2,i-1,j) , solve(s1,s2,prev1,prev2,i,j-1));
        }
        
       
    } */ // method is correct but for dp we have to create 2d dp 
  int maxi =0;
   int solve(int i, int j, string &s1 , string &s2 , int count,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(s1[i]==s2[j]){
           count = count+1;
           ans = solve(i-1,j-1,s1,s2,count,dp);
           dp[i][j] = count;
           maxi =   max(maxi,dp[i][j]);
          
        }
        else{
           int case1 = solve(i-1,j,s1,s2,0,dp);
           int case2 =  solve(i,j-1, s1,s2,0,dp);
           dp[i][j]=0;
           maxi = max(maxi , count);
         //  ans = max(case1 , case2);
          // ans =  max(count,max(case1,case2));
            
        }
        return dp[i][j];
    }
    
 public:   
    int longestCommonSubstr (string S1, string S2)
    {
        // 2 string => how to apply sliding window or prefix sum 
        // return solve(S1,S2,-1,-1,S1.size()-1, S2.size());
       int n = S1.size();
       int m = S2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       int ans = 0;
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(S1[i-1]==S2[j-1]){
                   dp[i][j] = 1+dp[i-1][j-1];
                   ans = max(ans , dp[i][j]);
               }
               else{
                   dp[i][j]=0;
               }
           }
       }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends