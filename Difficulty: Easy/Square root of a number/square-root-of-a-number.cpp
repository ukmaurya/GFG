//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
#define ll long long
class Solution {
  public:
    long long int floorSqrt(long long int n) {
           
           ll start = 1;
           ll end = n ;
           ll ans =-1;
           while(start<= end){
               ll mid = start+(end-start)/2;
               if(mid*mid<= n){
                   ans = mid;
                   start = mid+1;
               }
               else{
                   end = mid-1;
               }
           }
           return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends