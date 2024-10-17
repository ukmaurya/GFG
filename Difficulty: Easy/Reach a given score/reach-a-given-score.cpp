//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

#define ll long long 
class Solution
{
     long long int fun(int i,long long int n,vector<int> &v,vector<vector<long long int>> &dp){
        if(n==0)
            return 1;
        if(i<0)
            return 0;
    
        if(dp[i][n]!=-1)
            return dp[i][n];
    
        long long int t=0;
        if(n>=v[i])
            t=fun(i,n-v[i],v,dp);
        long long int nt=fun(i-1,n,v,dp);
        
        return dp[i][n]=t+nt;
    }
    public:
    // Complete this function
    long long int count(long long int n)
    {
        vector<int> v={3,5,10};
        
        vector<vector<long long int>> dp(3,vector<long long int>(n+1,-1));
        return fun(2,n,v,dp);
    
    
      // below methos is incorrect     
    //   vector<ll> dp(n+1, -1);
    //   return func(n,dp);
    	
    	// Problem is that you like for eg 17 you are considering 
    // 	3 3 3 3 5, 3 3 3 5 3, 3 3 5 3 3, 3 5 3 3 3, 5 3 3 3 3, 
    // 	there are 5 ans you are getting but actually no. of 3 and  5 are
    // 	same in all cases all are duplicates so answer is 1
      }
    ll func(int n,  vector<ll>&dp){
        if( n ==0 ){
            return 1;
        }
        if(n<0){
            return 0;
        }
      if(dp[n] != -1){
          return dp[n];
      }
       
        ll  a = func(n-3, dp );
        ll b= func(n-5 , dp);
      ll c= func(n-10 ,dp);
        
        return dp[n] = a+b+c;
     }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends