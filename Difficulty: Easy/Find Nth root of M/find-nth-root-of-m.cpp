//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	       long long start = 0;
          long long end = m;
          long long ans = 0;
          while(start<=end){
              long long mid = start+(end -start)/2;
               if(pow(mid,n) == m){
                  ans = mid;
                  return ans;
                  
              }
              else if(pow(mid,n) > m){
                 
                  
                  end = mid-1;
                  
              }
              else{
                  start = mid+1;
              }
          }
          
          return -1;
	}  
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends