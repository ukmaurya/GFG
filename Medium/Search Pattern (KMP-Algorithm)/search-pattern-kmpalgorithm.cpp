//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<int> calLPS(string pat){
        int n = pat.size();
        vector<int> lps(n,0);
        int prefix = 0;
        int suffix = 1;
        while(suffix<n){
            if(pat[prefix]==pat[suffix]){
                lps[suffix]=prefix+1;
                prefix++;
                suffix++;
            }
            else{
                if(prefix==0){
                    lps[suffix]=0;
                    suffix++;
                }
                else{
                    prefix = lps[prefix-1];
                }
            }
        }
        return lps;
    }
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            
            vector<int> lps = calLPS(pat);
            
            // using KMP
            int n = txt.size();
            int m = pat.size();
            vector<int> ans;
            int t=0; // pointer of text
            int p=0;
            while(t<n){
               
                if(txt[t]==pat[p]){
                    t++;
                    p++;
                  if(p==m){
                    ans.push_back(t-p+1); // one based indexing 
                    
                    p=lps[p-1];
                  }
                }
                else{
                    if(p==0){
                        t++;
                    }
                    else{
                        p= lps[p-1];
                    }
                }
                
            }
            if(ans.size()==0){
                return{-1};
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
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends