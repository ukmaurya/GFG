//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        // using xor propertise we can do it in constant time 
      
      // xor till r
        int xor_till_r=0;
        if(r%4==0) xor_till_r=r;
        else if(r%4==1) xor_till_r=1;
        else if(r%4==2) xor_till_r=r+1;
        else if( r%4==3) xor_till_r=0;
      
        // XOR till l-1 
        int xor_till_l=0;
        if((l-1)%4==0) xor_till_l=l-1;
        else if((l-1)%4==1) xor_till_l=1;
        else if((l-1)%4==2) xor_till_l=l-1+1;
        else if( (l-1)%4==3) xor_till_l=0;
        
        // xor till r - xor till l;
        int ans= xor_till_l ^ xor_till_r;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends