//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    bool solve(int i, int j, int k , string& a , string& b, string& c){
        int n = a.size();
        int m = b.size();
        int z = c.size();
        if(k==z){
            return true;
        }
        if(a[i]==c[k] && b[j]==c[k]){
            bool first = solve(i+1,j,k+1,a,b,c);
            bool second = solve(i,j+1,k+1,a,b,c);
            return first||second;
        }
        else if(a[i]==c[k]){
            return solve(i+1,j,k+1,a,b,c);
        }
        else if(b[j]==c[k]){
            return  solve(i,j+1,k+1,a,b,c);
        }
        else{
            return false;
        }
    }
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        if(A.size()+B.size()  != C.size())
          return false;
         return solve(0,0,0,A,B,C);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends