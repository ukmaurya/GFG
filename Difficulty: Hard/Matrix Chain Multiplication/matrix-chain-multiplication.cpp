//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int i, int j , int arr[]){
        if(i==j){ // only one matrix
            return 0;
        }
        int ans = INT_MAX;
        
        // partition 
        for(int k = i ;k<=j-1; k++ ){
            int cost = solve(i,k, arr )+solve(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
            ans = min(ans , cost);
        }
        return ans;
        
        
       
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        //   int i = 1;
        //   int j = N-1;
         // return solve(i,j,arr);
         
         vector<vector<int>>dp(N+1 ,vector<int>(N+1,0));
         for(int i=N-1;i>=1;i--){
             for(int j=1;j<=N-1;j++){
                 if(j<=i) // j<i will be wrong due to k loop condition
                   continue;
                  int ans = INT_MAX;
                   // partition 
                    for(int k = i ;k<=j-1; k++ ){
                        int cost = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                        ans = min(ans , cost);
                       
                        
                    }
                     dp[i][j]=ans;
                }
         }
         return dp[1][N-1];
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