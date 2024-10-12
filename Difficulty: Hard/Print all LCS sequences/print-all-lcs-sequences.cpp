//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{ 
    private:
    //   void solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp, string ans, set<string>& res) {
    //         if (i == 0 || j == 0) {
    //             reverse(ans.begin(), ans.end());
    //             res.insert(ans);
    //             return;
    //         }
    //         if (s1[i-1] == s2[j-1]) {
    //             ans += s1[i-1];
    //             solve(s1, s2, i-1, j-1, dp, ans, res);
    //             ans.pop_back();
    //         } 
    //         else {
    //             if (dp[i][j] == dp[i-1][j]) {
    //                 solve(s1, s2, i-1, j, dp, ans, res);
    //             }
    //             if (dp[i][j] == dp[i][j-1]) {
    //                 solve(s1, s2, i, j-1, dp, ans, res);
    //             }
    //         }
    //     }
    void solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp, string ans, set<string>& res , unordered_map<string , bool>&mp) {
            if (i == 0 || j == 0) {
                reverse(ans.begin(), ans.end());
                res.insert(ans);
                return;
            }
            //generate key using i,j index +lcs formed till these index 
            string key = to_string(i)+","+to_string(j)+","+ans;
            if(mp.find(key) != mp.end())
              return ; // avoiding the already caluled task 
            mp[key]= true;  
            if (s1[i-1] == s2[j-1]) {
                ans += s1[i-1];
                solve(s1, s2, i-1, j-1, dp, ans, res,mp);
                ans.pop_back();
            } 
            else {
                if (dp[i][j] == dp[i-1][j]) {
                    solve(s1, s2, i-1, j, dp, ans, res,mp);
                }
                if (dp[i][j] == dp[i][j-1]) {
                    solve(s1, s2, i, j-1, dp, ans, res,mp);
                }
            }
        }
	public:
		vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		    int n = s1.size();
            int m = s2.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // DP table
            
            // Fill the DP table
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s1[i-1] == s2[j-1]) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            
         set<string>res;
         unordered_map<string , bool> mp; 
         solve(s1,s2,n,m,dp,"",res , mp);
         vector<string> result(res.begin(), res.end());
         return result ;



       // below logic is correct but  it is giving TLE so we will use dp in backtracking also 
            
            
            
        //     set<string> res; // Using set to avoid duplicates
        //     solve(s1, s2, n, m, dp, "", res);
            
        //     vector<string> result(res.begin(), res.end());
        //   // sort(result.begin(), result.end()); // Ensure lexicographical order
        //     return result;
	   }
};





//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends