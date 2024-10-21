//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
    int solve(int station ,int line,vector<vector<int>>&a , vector<vector<int>>& t ,vector<int>&x , vector<vector<int>>&dp){
        
        int n = a[0].size();
        if(station == n-1 ){
           return a[line][station] + x[line];
        }
        if(dp[station][line]!= -1)
          return dp[station][line];
        int sameLine  = solve(station+1,line ,a ,t,x,dp)+a[line][station];
        int diffLine  = solve(station+1,1-line,a ,t,x,dp)+a[line][station]+t[line][station+1];
         
        
        return dp[station][line] = min(sameLine , diffLine);
        
        
        
        
    }
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
       
       int n = a[0].size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        int line0 = solve(0,0,a,T,x,dp)+e[0];
        int line1 = solve(0,1,a,T,x,dp)+e[1];
        return min(line0 , line1);
    
      
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends