//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int start , int end , int arr[],vector<vector<int>>&dp){
        if(start == end)
          return 0;
        if(dp[start][end]!=-1)
          return dp[start][end];
        // see various possibilities
        int mini = INT_MAX;
        int cost =0;
        for(int i= start ;i<end;i++){
            int left = solve(start,i,arr,dp);
            int right = solve(i+1,end, arr,dp);
            cost = left+right+arr[start-1]*arr[i]*arr[end];
            mini = min(mini , cost);
        }
        return dp[start][end] = mini;
        
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
          vector<vector<int>>dp(N,vector<int>(N,-1));
          return solve(1,N-1,arr,dp);
        
        
          /*vector<vector<int>>dp(N,vector<int>(N,0));
        // initialisation 
        for(int i=0;i<N;i++){
            dp[i][i]=0;
        }
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int ans = INT_MAX;
                for(int k=i;k<=j-1;k++){
            
                     int par = dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j]; // arr[i-1]*arr[k]*arr[j] is cost to 
            // to multiply 2 matrices of dimension arr[i-1],arr[k] ans arr[k],arr[j]
            ans = min(ans, par);
        }
        dp[i][j]=ans; */
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends