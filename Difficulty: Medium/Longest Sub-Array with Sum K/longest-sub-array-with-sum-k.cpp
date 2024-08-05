//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
           unordered_map<int , int> mp; // preSUM , last index
           mp[0]=-1;
           int preSum =0;
           int ans =0;
           for(int i=0;i<N;i++){
               int len = 0;
               preSum+=A[i];
               int req = preSum-K;
               if(mp.find(req) != mp.end()){ 
                    len = i-mp[req]; 
                    ans = max(ans , len );
               }
               if(mp.find(preSum) == mp.end()){
                      mp[preSum]=i; // donot change the index if found
               }
              
           }
           
           return ans;
    } 

};


//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends