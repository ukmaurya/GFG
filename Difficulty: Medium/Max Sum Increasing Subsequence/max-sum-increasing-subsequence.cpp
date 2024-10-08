//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> sum(n,0);
	    int maxi =0;
	    
	    for(int i=0;i<n;i++){
	        sum[i] = arr[i];
	        int j = i-1;
	        while(j>=0){
	            if(arr[i]>arr[j]){
	                sum[i] = max(sum[i] , sum[j]+arr[i]);
	            }
	            j--;
	        }
	        maxi = max(maxi , sum[i]);
	    }
	    return maxi;
	  
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends