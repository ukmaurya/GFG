//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    // int solve(int keys[] , int level ,int ps,int pe, vector<pair<int, int >>&preorder ,int ins , int ine, int n ){
    //     if(ps>pe){
    //         return 0;
    //     }
    //     if(ins>ine){
    //         return 0;
    //     }
    //     int freq = preorder[ps].first;
    //     int index = preorder[ps].second;
    //     int cost = level*freq;
    //     if(index>=0){
    //         cost += solve(keys , level+1 , ps+1,);
    //     }
    //     if(index<=n-1)
    //         cost += solve(keys , level+1 , index+1, preorder , n);
        
    //     return cost;
    // }
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
    //   vector<pair<int, int >> preorder ;
    //   for(int i=0;i<n;i++){
    //       preorder.push_back({freq[i] , i});
    //   }
    //   sort(preorder.begin() , preorder.end());
    //   return solve(keys , 1 ,0,n-1,preorder,0,n-1 n );
    //above method fails since we are not able to find which should be root of left and right
    // means we are able to find whih are higer frequency , but of not weather it should be root of left or right 
    
    
    // approach 1 : giving TLE since 3d dp of n size of each dimension 
     // just like partition dp
     //vector<vector<vector<int>>>dp(n , vector<vector<int>>(n,vector<int>(n,-1)));
     // return solve(0,n-1,1,keys , freq ,dp );
     
     // approach 2 : aptimised to 2d dp 
       vector<vector<int>> dp(n,vector<int>(n,-1));
       return mincostree(freq,0,n-1,dp);
     
   
     }
     
     int solve(int i, int j , int level ,int keys[] , int freq[],vector<vector<vector<int>>>&dp ){
         if(i>j){
             return 0;
         }
         if(i==j){
             return level*freq[i];
         }
         if(dp[i][j][level]!= -1){
             return dp[i][j][level];
         }
         
        int ans = INT_MAX;
        for(int k=i;k<=j;k++){
            int cost = level*freq[k];
            cost += solve(i,k-1 , level+1 , keys , freq ,dp);
            cost += solve(k+1 , j , level+1 , keys , freq,dp);
            ans = min(cost, ans);
        }
        return dp[i][j][level] = ans;
     }
      int mincostree(int freq[], int i, int r, vector<vector<int>>& dp) {
        
        if(i>r) {
            return 0;
        }
        
        if(dp[i][r]!=-1) {
            return dp[i][r];
        }
        
        int ans=INT_MAX;
        
        for(int j=i; j<=r; ++j) {
            int left=mincostree(freq,i,j-1,dp);
            int right=mincostree(freq,j+1,r,dp);
            ans=min(ans,left+right);
        }
        for(int j=i; j<=r; ++j) {
                ans+=freq[j];
            }
        return dp[i][r]=ans;
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
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends