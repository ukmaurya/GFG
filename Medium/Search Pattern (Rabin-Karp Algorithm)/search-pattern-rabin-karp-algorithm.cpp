//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 
class Solution
{
   

public:
    vector<int> search(string pattern, string text) {
         vector<int> ans;
            int d = 256;
            int q = INT_MAX;
            string p = pattern;
            string t = text;
            int n = t.length();
            int m = p.length();
            int t0 = 0;
            int p0 = 0;
            for(int i = 0; i < m; i++){
                t0 = (t0*d + t[i])%q;
                p0 = (p0*d + p[i])%q;
            }
            int x = 1;
            for(int i = 0; i < m-1; i++){
                x = (x*d)%q;
            }
            
            int i = 0;
            while(i<=n-m){
                // cout<<p0<<" "<<t0<<endl;
                if(t0==p0){
                    int j = 0;
                    while(j<m && t[i+j]==p[j]){
                        j++;
                    }
                    if(j==m) ans.push_back(i+1);
                }
                if(i<n-m){
                    
                    t0 = ((t0-t[i]*x)*d+ t[i+m])%q;
                    if(t0<0){
                        t0 = t0+q;
                    }
                }
                
                i++;
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