//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	   /* vector<bool> sieve(N+1 , true);
	    sieve[0]=sieve[1]=false;
	    for(int i=2;i*i<=N;i++){
	        if(sieve[i]==true){
	            for(int j=2*i;j<=N; j+=i ){
	                sieve[j] = false;
	            }
	        }
	    }
	    vector<int> ans;
	    for(int i=2;i<=N;i++){
	        if(sieve[i]==true && N%i==0){
	            ans.push_back(i);
	        }
	    }
	    return ans; */
	    
	    // above solution was giving TLE
	    vector<int> ans;
	    for(int i=2;i<=N;i++){
	        while(N%i==0){
	            if(ans.size()==0 || ans.back()!= i){
	                ans.push_back(i);
	               
	            }
	             N=N/i;
	        }
	        
	    }
	    if(N>1){ // number if prime 
	        ans.push_back(N);
	    }
	   return ans; 
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends