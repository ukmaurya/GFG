//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        
        int n = s.size();
        int index=-1;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
               count--;
               if(count==0){
                   index = i+1;
                   break;
               }
            }
        }
        if(index==-1 || index>=n){
            return "";
        }
        return s.substr(index , n-index+1);
        }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends