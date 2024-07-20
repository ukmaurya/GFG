//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
             // we cannot directly apply kadane algorithm with concatinatiing arraye
         /*
         
Doubling the array to solve the maximum subarray sum in a circular array seems like a straightforward solution at first glance, but it introduces several complexities that make it an impractical approach. Let's explore the reasoning in detail.

Concept of Doubling the Array
The idea behind doubling the array is to concatenate the array with itself, thus transforming the problem of finding a maximum sum subarray in a circular array to finding a maximum sum subarray in a linear array. For example, if the original array is [5, -3, 5], doubling it would produce [5, -3, 5, 5, -3, 5].

Issues with Doubling the Array
Subarray Boundaries:

In the doubled array, you must ensure that any subarray considered as a potential maximum subarray does not exceed the logical boundaries of the original array. For example, if the original array has a length of n, any subarray in the doubled array must span at most n elements.
Overlapping Subarrays:

While traversing the doubled array, you need to be careful about overlapping subarrays. If you blindly apply Kadane's Algorithm to the doubled array, it might incorrectly consider subarrays that include more than n elements, leading to incorrect results.
         
         */
         
         
            // approach 1: total - min subarray sum 
            int total = 0;
            for(int i=0;i<num;i++){
                total+=arr[i];
            }
            
            
            //  minimum subarray sum
            int mini =0;
            int sum=0;
            for(int i=0;i<num;i++){
                if(sum>0){
                    sum = arr[i];
                }
                else{
                    sum+=arr[i];
                }
                mini = min(mini , sum);
                
            }
             
            int ans1 = total- mini;  // considering wrapping of subarray 
         //    cout<<ans1 <<" ";
             // now cal ans without considering wrapping of subarray 
             int maxi = INT_MIN;
             int jod = 0;
             for(int i=0;i<num;i++){
                
                if(jod<0){
                    jod = arr[i];
                }
                else{
                    jod+=arr[i];
                }
                maxi = max(maxi, jod);
                
            }
            int ans2 = maxi;
           // cout<<ans2<<" ";
            if(maxi<0)
             return maxi;
            return max(ans1 , ans2);
            
            
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends