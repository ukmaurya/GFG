//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int mod = 1e9+7;
    private:
    int solve(int index , vector<int>&dp){
        if(index==0 ||index==1 || index==2){
            return dp[index] = 1;
        }
        if(dp[index]!=-1)
         return dp[index]%mod;
        
        return dp[index] = (solve(index-2 , dp)%mod+solve(index-3 ,dp)%mod)%mod; 
    }
    public:
    int padovanSequence(int n)
    {
      vector<int> dp(n+1,0);
      dp[0]=dp[1]=dp[2]=1;
      for(int i=3;i<=n;i++){
          dp[i] = (dp[i-2]%mod+dp[i-3]%mod)%mod;
      }
      return dp[n];
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends