//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#define ll long long 
class Solution{
  public:
    long long findRank(string str) {
       
       vector<int>freq(26,0);
       int n = str.size();
       for(int i=0;i<n;i++){
           freq[str[i]-'a']++;
       }
       vector<ll > fact(n,0);
       fact[0] = fact[1] =1;
       for(int i=2;i<n;i++){
           fact[i] = fact[i-1]*i;
       }
       
       ll ans = 0;
       for(int i=0;i<n;i++){
           int temp=0;
           for(int j=0;j<str[i]-'a';j++){
              temp += freq[j];
           }
           ans += temp* fact[n-1-i];
           freq[str[i]-'a']--;
          }
       
       return ans+1;
       
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends