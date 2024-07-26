//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
    private:
    ll catalan(int n)
{
    ll res = 1;
     for (int i = 1; i <= n; i++) { // using reduction of formula 
        res = (res *1LL*(4 * i - 2)) / (i + 1);
       
       }
    return res;
}
  public:
    long long dyckPaths(int N) {
       return catalan(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.dyckPaths(N) << endl;
    }
    return 0;
}
// } Driver Code Ends