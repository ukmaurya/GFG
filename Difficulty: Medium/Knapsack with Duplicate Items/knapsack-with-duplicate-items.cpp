//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int N ,int W , int val[] ,int wt[],vector<vector<int>> &dp){
        if(W == 0 ) return 0;
        if(N==0){
            if( W >= wt[0] ){
                int temp = W/wt[0];
                return temp*val[0];
            }
            else return 0;
        }
        if(dp[N][W] !=-1) return dp[N][W];
        int ex= solve(N-1 ,W,val,wt,dp );
        int in = 0;
        if(W >= wt[N])
           in = solve(N, W-wt[N] ,val,wt,dp) + val[N];
           
         return dp[N][W]=max(ex, in);  
        
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {   
        // vector<vector<int>> dp(N,vector<int>(W+1,-1));
        // return solve(N-1, W, val , wt ,dp);
         vector<vector<int>> dp(N+1,vector<int>(W+1,0));
         for(int i=0;i<=W;i++){
            if( i >= wt[0] ){
                int temp = i/wt[0];
                dp[0][i] = temp*val[0];
            } 
         }
         
         for(int i=1;i<N;i++){
             for(int j=0;j<=W;j++){
                 int ex = dp[i-1][j];
                 int in=0;
                 if(wt[i]<=j){
                     in = dp[i][j-wt[i]]+val[i];
                 }
                 dp[i][j] = max(in,ex);
             }
         }
        
        return dp[N-1][W];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends