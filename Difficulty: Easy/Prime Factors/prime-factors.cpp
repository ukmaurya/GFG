//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
     bool checkPrime(int n ){
        int count=0;
        for(int i=1;i*i<=n;i++){ // are we have not used sqrt function since in stl sqrt 
                                 // takes log n times 
            if(n%i==0){
                count++;
                if((n/i) != i) // since alst factors will be same 
                  count++;
            }
        }    
        if(count==2) return true;
        return false;
    }
	public:
	vector<int>AllPrimeFactors(int N) {
	    if(N==1)
	      return { };
	     vector<int> ans;
	     for(int i=2;i*i<=N;i++){
	         if(N%i==0 && checkPrime(i)){
	             ans.push_back(i);
	          
	         }
	        if( N%i==0 && N/i != i && checkPrime(N/i)){
	             ans.push_back(N/i);
	            }
	       
	     }
	     if( N>1 && checkPrime(N)){
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
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends