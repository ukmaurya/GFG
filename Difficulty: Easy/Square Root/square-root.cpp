//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
          int start = 0;
          int end = sqrt(n);
          int ans = -1;
          while(start<=end){
              int mid = start+(end-start)/2;
              if(mid*mid<=n){
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
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends