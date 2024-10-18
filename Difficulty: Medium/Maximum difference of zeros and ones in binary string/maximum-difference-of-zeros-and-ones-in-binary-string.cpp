//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // 2 states=> use +, -1 technique then kadanes algo 
	    
	    string temp = S;
	    int n = temp.size();
	    for(int i=0;i<n;i++){
	        if(temp[i]=='0'){
	            temp[i]='1';
	        }
	        else{
	            temp[i]='0'; // denoting -1;
	        }
	    }
	    
	    // apply kadanes algo 
	    int maxi =INT_MIN;
	    int sum=0;
	    for(int i=0;i<n;i++){
	        if(temp[i]=='1'){
	            sum += 1;
	        }
	        else{
	            sum-= 1;
	        }
	        maxi = max(sum ,maxi);
	        if(sum<0){
	            sum = 0;
	        }
	    }
	    return maxi ;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends