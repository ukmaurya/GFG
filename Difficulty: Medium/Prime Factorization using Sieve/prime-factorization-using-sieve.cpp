//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
        int n = N;
       vector<int> spf(n+1,0);  // sieve array
     for(int i=1;i<=n;i++){
            spf[i]=i; // initilize with number itself
        }
        // mark every number with its smallest prime factor
        for(int i=2;i*i<=n;i++){
            if(spf[i]==i){  // i is prime  
                for(int j=i*i;j<=n;j+=i){
                    if(spf[j]==j){  
                        spf[j]=i; // mark with spf ie smallest prime factor
                    }
                }
            }
        }
    
      vector<int> ans;
      while(n != 1){
          ans.push_back(spf[n]);
          n=n/spf[n];
      }
       sort(ans.begin(),ans.end());
      return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends