//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int ans =0;// global since we have to iterate dp 2d array ---see tabulation method
      int solve(string&s,string &str,int p1,int p2,vector<vector<int>>&v){
        if(p1==s.size()||p2==str.size()){
            return 0;
        }
        if(v[p1][p2]!=-1){
            return v[p1][p2];
        }
        int cnt=0;
        if(s[p1]==str[p2]){
            cnt=1+solve(s,str,p1+1,p2+1,v);
            ans=max(cnt,ans);
        }
    
             int ans1=solve(s,str,p1+1,p2,v);
             int ans2=solve(s,str,p1,p2+1,v);
        
         
       return  v[p1][p2]=cnt;
    }
    
    int longestCommonSubstr (string S1, string S2)
    {
        // memoized
        int n = S1.size();
        int m = S2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1,-1));
        int temp = solve(S1,S2,0,0,v); // note temp is not used
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends