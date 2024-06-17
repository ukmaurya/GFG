//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution{
   ll mod = 1e9+7;
    private:
    ll solve(string str , int i , int j ,vector<vector<ll>>&dp ){
        if(i>j)
         return 0;
        if(i==j)
         return 1;
        if(dp[i][j] != -1)
         return dp[i][j];
        ll ans = 0;
        if(str[i]==str[j]){
            ans = (1+solve(str,i+1,j,dp)%mod+solve(str,i,j-1,dp)%mod)%mod;
        }
        else{
            ans = (solve(str,i+1,j,dp)%mod+solve(str,i,j-1,dp)%mod-solve(str,i+1,j-1,dp)%mod)%mod;
        }
        return dp[i][j]= ans%mod;
    }
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
      /* int n = str.size();
       vector<vector<ll>> dp(n,vector<ll>(n,-1));
       return solve(str,0,str.size()-1,dp)%mod; */
       
        int n = str.length();
       vector<vector<long long int>> dp(n,vector<long long int>(n,0));
       for(int i=0;i<n;i++)
       dp[i][i]=1;
       for(int i=n-1;i>=0;i--)
       {
           for(int j=i+1;j<n;j++)
           {
                long long int num=0;
                num = (dp[i][j-1]%mod + dp[i+1][j]%mod)%mod;
        
                if(str[i]==str[j]) num=(num+1)%mod;
        
                else num = (num - dp[i+1][j-1])%mod;
                dp[i][j] = num<0 ? num+mod : num;
           }
       }
       
       return dp[0][n-1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends