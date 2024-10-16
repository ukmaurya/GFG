//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool solve(int n , int &x, int &y ,int turn,vector<vector<int>>&dp){
        if(n==0){
            return turn==1?0 : 1;
        }
        
        if(dp[n][turn] != -1){
            return dp[n][turn];
        }
        bool case1 , case2 , case3;
        if(turn == 1 ){
            case1 = case2 = case3 = false;
            if(n-1>=0){
                case1 = solve(n-1 , x,y,1-turn,dp);
            }
            if(n-x>=0){
                case2 = solve(n-x, x,y,1-turn,dp);
            }
            if(n-y>=0){
                case3 = solve(n-y , x, y , 1-turn,dp);
            }
            return dp[n][turn] = case1||case2||case3;
        }
        else{
            case1 = case2 =case3 = true;
            if(n-1>=0){
                case1 = solve(n-1 , x,y,1-turn,dp);
            }
            if(n-x>=0){
                case2 = solve(n-x, x,y,1-turn,dp);
            }
            if(n-y>=0){
                case3 = solve(n-y , x, y , 1-turn,dp);
            }
            return dp[n][turn] = case1&&case2&&case3;
        }
        
        return false;  
    }
  public:
    int findWinner(int n, int x, int y) {
          vector<vector<int>>dp(n+1,vector<int>(2 , -1)); // 1- true , 0 -- false , -1 not calculated 
          return solve(n,x,y,1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends