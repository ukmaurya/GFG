//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
      int solve(int i,int j,int cnt,int k,vector<int> &arr,vector<vector<int>> &dp){
        if(arr[j]-arr[i] <= k) return cnt;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int start = solve(i+1,j,cnt+1,k,arr,dp);
        int end = solve(i,j-1,cnt+1,k,arr,dp);
        
        return dp[i][j] = min(start,end);
        
    }
    public:
    int removals(vector<int>& arr, int k){
         
        //  int n = arr.size();
        //  sort(arr.begin() , arr.end());
        //  int count =0;
        //  int i=0;
        //  int j=n-1;
        //  while(i<j){
        //      if(arr[j]-arr[i]>k){
        //          j--;
        //          count++;
        //      }
             
        //  }
        //  return count.   
        // above will give wrong ans 
          sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(0,n-1,0,k,arr,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends