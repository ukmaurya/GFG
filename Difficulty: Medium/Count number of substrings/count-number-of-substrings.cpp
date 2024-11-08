//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private: 
    int atmost(string s, int k){
          int n = s.size();
          int i=0;
          int j=0;
          int ans=0;
          unordered_map<char,int> mp;
          while(j<n){
              mp[s[j]]++;
              if(mp.size() <= k){
                  ans += j-i+1;
                  j++;
              }
              else{
                  while( i<j && mp.size()>k){
                      mp[s[i]]--;
                      if(mp[s[i]]==0){
                          mp.erase(s[i]);
                      }
                      i++;
                      
                  }
                  if(mp.size()<=k){
                      ans+= j-i+1;
                     
                  }
                  j++;
              }
          }
          //cout<<ans<<endl;
          return ans;
    }
  public:
    long long int substrCount (string s, int k) {
        
        //aaacaaa , shrinking is happing both the sides 
        return atmost(s,k)-atmost(s,k-1);
         
    }
};


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends