//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
       void permute(int index , string s ,  vector<string>&ans){
         
          // optimised than previous in terms of space 
          if(index == s.size()){
              ans.push_back(s);
              return;
              
          }
          unordered_map<char , int > mp; // helping in constrained branches 
          for(int i = index; i<s.size() ;i++){
              if(mp.find(s[i]) == mp.end()) // to avoid duplicates movement 
               {
                 
              mp[s[i]]++;
              swap(s[index] , s[i]);
              permute(index+1, s,ans);
              swap(s[index] , s[i]); // backtrack step 
               }
          }
           
       }
    
	public:
		vector<string>find_permutation(string S)
		{
		 //using backtracking concept
		 vector<string> ans;
		  permute(0,S,ans);
		  return ans;
		  
		}
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends