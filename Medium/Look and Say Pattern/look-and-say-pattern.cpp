//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
      string solveRLE(string s){
       
        string ans ="";
        for(int i=0;i<s.size();){
            int count=0;
            char cur = s[i];
            int index = i;
            while(index<s.size() && s[index]==cur){
                index++;
                count++;
            } 
            ans.push_back(count+'0');
            ans.push_back(cur);
            i = index;
        }

         return ans;
    }
  public:
    string lookandsay(int n) {
        // code here
        
        if(n==1){
          return "1";
        }
        string ans = lookandsay(n-1);
        string res = solveRLE(ans);
        return res;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends