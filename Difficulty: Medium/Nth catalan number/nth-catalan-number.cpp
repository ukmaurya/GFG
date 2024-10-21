//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  int mod = 1e9+7;
  vector<int> fact;
  long long  binExp(long long a , long long b){
        if(a==1)
          return 1;
        else if(b==1){
            return a;
        }  
        a = a%mod;
        b = b%mod;
        long long  ans = 1;
        while(b){
            if(b&1){
                ans=(ans*a)%mod;
            }
            b = b>>1;
            a = (a*a)%mod;
        }
        return ans;
    }
    void factorial(int n ){
         fact.resize(n+1);
       fact[0]=fact[1]=1;
       for(int i=2;i<=n;i++){
           fact[i] = (fact[i-1]*1LL*i)%mod;
       }
    }
    int nCr(int n, int r){
       if (r > n) return 0; // nCr is 0 if r > n
      
      factorial(n);
       // inverse modulo  , or it can be also done be reverse factorial
       // Using Fermat's Little Theorem
       long long modInverse1 = binExp(fact[r] , mod-2)%mod; // inverse mod of b  = pow(b,mod-2)
       long long  modInverse2 = binExp(fact[n-r] ,mod-2)%mod;
       
       long long  ans = (((fact[n]*1LL*modInverse1)%mod)*1LL*modInverse2)%mod;
       return ans;
       
    }
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
         //Catalan Number (2*n)!/((n+1)! * n!)
         
         factorial(2*n+1);
         long long modInverse1 = binExp(fact[n+1],mod-2);
         long long modInverse2 = binExp(fact[n],mod-2);
         long long ans = (((fact[2*n]*1LL*modInverse1)%mod)*modInverse2)%mod;
         return ans;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends