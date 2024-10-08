//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    
	    int mod = 1e9+7;
	    
	    ll endOne =1;
	    ll endZero = 1;
	    for(int i=2;i<=n;i++){
	        ll tempOne = endZero%mod;
	        ll tempZero =( endOne+endZero)%mod;
	        endOne = tempOne;
	        endZero = tempZero;
	     }
	     return( endOne+endZero)%mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends