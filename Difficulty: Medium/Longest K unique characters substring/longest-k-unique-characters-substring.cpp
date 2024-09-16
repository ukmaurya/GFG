//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        string str = s; 
        int n = str.size();
         unordered_map<char , int > mp;
         int i = 0;
         int j =0;
         int ans = -1;
         while(j<n){
             mp[str[j]]++;
             if(mp.size()<k){
                 j++;
             }
             else if(mp.size()==k){
                 ans = max(ans , j-i+1);
                 j++;
             }
             else{
                 while(mp.size()>k){
                     mp[str[i]]--;
                     if(mp[str[i]]==0){
                         mp.erase(str[i]);

                     }
                     i++;
                 }
                  
                 j++;
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends