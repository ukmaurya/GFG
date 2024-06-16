//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
          
        string s = pat + '$' + txt; // concatenate pattern, a special character, and the text
        int n = s.size();
        int m = pat.size();
        vector<int> z(n, 0);
        // Z-function construction
        int l = 0;
        int r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {  // Handle case of z[i] reaching beyond  r
                // consider ex : aaaaab
                                 //    z :044 .... 
                z[i] = min(r - i + 1, z[i - l]);
            }
             
                 // more match beyond the r may also possible some times 
                 /*
                 consider ex : ababadabababab
                          z  : 003010503....*/
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            // update l and r
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        vector<int> ans;
        // Collecting the results where pattern matches in the text
        for (int i = m + 1; i < n; i++) {
           
            if (z[i] == m) {
                ans.push_back(i - m); // 0-based index of the starting position of the match
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