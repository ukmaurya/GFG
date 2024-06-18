//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  
  bool solve(int n,vector<vector<int>>&dp, bool turn){
      // Base cases
        if(n == 1){
            if(turn==0){ 
                return false;
            }
            else return true;
        }
        if(n == 0){
          if(turn==1)
            return false;
          else 
            return true;        
        }
        if(dp[n][turn]!=-1) 
           return dp[n][turn];
        bool ans = (turn==true)?false:true;
        for (int i = 2; i <= 5; ++i){
            
          bool temp1 =  solve(n / i, dp,1-turn);
          bool temp2 = false;
          if(turn==true)
            temp2 = false;
          else 
            temp2 = true;    
          if(n - i >= 0){
               temp2 = solve(n - i,dp,1-turn);
            }
          if(turn==1){
              ans = ans||temp1||temp2;
          } 
          else{
              ans = ans&&(temp1)&&(temp2);
          }
          if(turn==1 && ans==true)
           break;
          if(turn==0 && ans==false)
           break;
           
        }

        return dp[n][turn] = ans;
   }
  public:
    string divAndSub(int N) {
        if(N==1)
         return "Arya";
       bool turn = true;
       vector<vector<int>> dp(N+1,vector<int>(2,-1));
       bool ans = solve(N,dp,true);
       if(ans==true)
         return "Jon";
       return "Arya";     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.divAndSub(N) << endl;
    }
    return 0;
}
// } Driver Code Ends