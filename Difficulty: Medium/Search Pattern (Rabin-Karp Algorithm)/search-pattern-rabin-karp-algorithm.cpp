//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
 public:
    vector<int> search(string pattern, string text) {
            vector<int> ans;
            int prime = 256; // we 
            int q = INT_MAX;
            string p = pattern;
            string t = text;
            int n = t.length();
            int m = p.length();
            int t_hash = 0;
            int p_hash = 0;
            for(int i = 0; i < m; i++){
                t_hash = (t_hash*prime + t[i])%q;
                p_hash = (p_hash*prime + p[i])%q;
            }
            int x = 1; // helpful in recalculating the hash 
            for(int i = 0; i < m-1; i++){
                x = (x*prime)%q;
            }
            for(int i=0;i<=n-m;i++){
               
                if(t_hash==p_hash){
                    int j = 0;
                    while(j<m && t[i+j]==p[j]){ // match the pattern
                        j++;
                    }
                    if(j==m) ans.push_back(i+1);
                }
                if(i<n-m){
                    t_hash = ((t_hash-t[i]*x)*prime+ t[i+m])%q;
                    if(t_hash<0){
                        t_hash = t_hash+q;
                    }
                }
                
              
            }
            return ans;
    }

};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends