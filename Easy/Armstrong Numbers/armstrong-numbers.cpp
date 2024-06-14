//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        
        // contraint are showing that number is 3 digit number 
        int num =n;
        int first = n%10;
        n=n/10;
        int sec = n%10;
        n=n/10;
        int third = n%10;
        int ans = first*first*first + sec*sec*sec + third*third*third;
         if(num==ans)
          return "true";
         return "false"; 
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends