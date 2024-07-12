//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{ 
   vector<int> lps(string s){
       int n = s.size();
       vector<int> ans(n,0);
       int i=0;
       int j=1;
       while(j<n){
           if(s[i]==s[j]){
               ans[j] = i+1;
               i++;
               j++;
              
           }
           else{ // instead of moving j , we will move i 
               if(i==0){
                  ans[j]=0;
                   j++;
               }
               else{
                   i = ans[i-1];
               }
            
           }
          
       }
       return ans;
   }
    
    public:
        vector<int> search(string pat, string txt)
        {
            int n  = pat.size();
            int m = txt.size();
            vector<int>LPS = lps(pat);
            vector<int> ans;
            int i=0;
            int j=0;
            while(j<m){
                if(pat[i]==txt[j]){
                    i++;
                    j++;
                    if(i==n){
                        ans.push_back(j-n+1);
                        i=LPS[i-1];
                    }
                }
                else{
                    if(i==0){
                        j++;
                    }
                    else{
                        i=LPS[i-1];
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