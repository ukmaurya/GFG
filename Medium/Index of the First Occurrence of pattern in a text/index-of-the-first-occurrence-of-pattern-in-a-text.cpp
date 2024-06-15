//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        
        unordered_map<string , int> mp;
        mp[pat]=1;
        int m = pat.size();
        int n = text.size();
        for(int i=0;i<n;i++){
            
            string s = text.substr(i,m);
            if(mp.find(s)!=mp.end())
              return i;
            
            
        }
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends