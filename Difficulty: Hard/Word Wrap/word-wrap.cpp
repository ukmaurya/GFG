//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
   
class Solution {
    int solve(int i, int k ,int useSpace , vector<int>&nums,vector<vector<int>>&dp){
       if(i==nums.size()){
           return 0;
       }
       if(dp[i][useSpace]!= -1){
           return dp[i][useSpace];
       }
       // now we have to put next word , it has two option to put in first line or second line
       // case 1 : put in next line 
       int case2 = solve(i+1 , k , nums[i] , nums,dp) + pow(k-useSpace,2);
       int newSpace = useSpace+1+nums[i];
       int  case1 = INT_MAX;
       if(newSpace<=k)
          case1 = solve(i+1 , k ,newSpace , nums,dp); // put in same line
        return dp[i][useSpace]=  min(case1, case2);
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
         vector<vector<int>>dp(nums.size()+1,vector<int>(k+1,-1));
        return solve(1,k,nums[0],nums,dp); // we have to plac first word in first 
                                       // line , for this there is no option 
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends