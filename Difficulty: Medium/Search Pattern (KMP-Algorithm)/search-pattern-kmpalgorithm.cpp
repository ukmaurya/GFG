//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{ 
   private: 
     vector<int> calLps(string &pat){
         int n = pat.size();
         vector<int> lps(n,0);
         int prefix =0;
         int suffix =1;
         while(suffix<n){
             
             if(pat[prefix]==pat[suffix]){
                 lps[suffix] = prefix+1;
                 prefix++;
                 suffix++;
             }
             else{
                 if(prefix==0){
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
        vector<int> search(string pat, string txt)
        {
           vector<int> lps = calLps(pat);
           int n = pat.size();
           int m = txt.size();
           int i =0;
           int j =0;
           vector<int> ans;
           while(j<m){
               if(pat[i]==txt[j]){
                   i++;
                   j++;
                   if(i==n){
                       ans.push_back(j-n+1);//one based indexing
                   }
               }
               else{
                   if(i==0){
                       j++;
                   }
                   else{
                      i= lps[i-1]; 
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