//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool check(int start , int end , string s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    private:
      int solve(int idx , string s,vector<int>&dp){
          int n = s.size();
           if( idx == n ){
              return 0;
          }
          if(check(idx , n-1 ,s)){
              return 0;
          }
          if(dp[idx]!=-1)
            return dp[idx];
          int ans = INT_MAX;
          for(int i=idx;i<n;i++){
              if(check(idx,i,s)){
                  ans = min(ans ,  1+solve(i+1,s,dp) );
              }
          }
          return dp[idx] = ans;
        }
public:
    int palindromicPartition(string str)
    {
       int n = str.size();
       vector<int>dp(n,-1);
       return solve(0,str,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends