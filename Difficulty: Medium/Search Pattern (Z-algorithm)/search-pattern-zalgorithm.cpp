//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
         
            string s = pat+'$'+txt;
            // in Z algorithm z[i] = longest prefix which is same as number of character starting at i
            // while in kmp we lps = longest prefix which is same as suffix 
            int n = s.size();
            int left = 0;
            int right = 0;
            vector<int>z(n,0);
            
            for(int i=1;i<n;i++){
               if(i<right){ // index is with right boundry 
                    z[i] = min(z[i-left] , right-i+1);
                }
                while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
                    z[i]++;
                }
                if(i+z[i]>right){ //update the boundry 
                     left = i;
                     right = i+z[i];
                }
                
            }
            
            vector<int> ans;
            int m = pat.size();
            for(int i=m+1;i<n;i++){
                if(z[i]==m){
                    ans.push_back(i-m);
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