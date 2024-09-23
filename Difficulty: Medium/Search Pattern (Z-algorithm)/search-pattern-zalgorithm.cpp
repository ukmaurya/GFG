//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
             txt = pat+"#"+txt;
             int n = txt.size();
             vector<int>z(n,0);
             int l =0;
             int r = 0;
             string s = txt;
             //same as manchers algorithm 
             for(int i=1;i<n;i++){
                 int mirr = i-l;
                 if(i<r){
                    z[i] = min(z[mirr] , r-i);
                 }
                    while(i+z[i]<n && s[z[i]]==s[i+z[i]]){ // in manchers we check s[i-z[i]]==s[i+z[i]]
                        z[i]++;
                    }
                    if(i+z[i]>r){
                        r = i+z[i];
                        l = i;  // in manchers algo we do l = i-z[i];
                    }
                      
                 
                 
             }
             
             // finding ansl
             vector<int> ans;
             for(int i=0;i<n;i++){
                 if(z[i]==pat.size()){
                    // cout<<i-pat.size()<<endl;
                     ans.push_back(i-pat.size());
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends