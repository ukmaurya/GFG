//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int solve(int idx , int prev , bool isGreater , vector<int>&arr,vector<vector<vector<int>>>&dp){
        int n = arr.size();
        if(idx==n){
            return 0;
        }
        if(dp[idx][prev+1][isGreater]!= -1){
            return dp[idx][prev+1][isGreater];
        }
        
        int take = 0;
        
        
        if(isGreater==true){
                int ele = (prev==-1)?INT_MIN:arr[prev];
                if(arr[idx]>ele){
                    take = 1+solve(idx+1 , idx , !isGreater , arr,dp);
                }
         }
         else{
             int ele = (prev==-1)?INT_MAX:arr[prev];
             if(arr[idx]<ele){
                 take = 1+solve(idx+1 , idx , !isGreater , arr,dp);
             }
         }
        int ntake = solve(idx+1 , prev , isGreater , arr,dp);
        return dp[idx][prev+1][isGreater] = max(take , ntake);
        
    }
  public:
    int alternatingMaxLength(vector<int>& arr) {
        
        // int n = arr.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1 , vector<int>(2,-1)));
        // int ans1 =  solve(0,-1,true,arr,dp);
        // int ans2 = solve(0,-1,false,arr,dp);
        // return max(ans1, ans2);
        // above was giving TLE 
        
        // applying greddy approach 
      if ( arr.size() == 0)
        return 0;

        int inc = 1; // length of sequence ending with increase
        int dec = 1; // length of sequence ending with decrease

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
            } 
            else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
            }
        }

        return max(inc, dec);
        
                    
                    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends