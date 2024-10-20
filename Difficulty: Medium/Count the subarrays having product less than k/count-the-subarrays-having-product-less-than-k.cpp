//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>&nums, int n, long long k) {
          if(k==0)
         return 0;
        //  int n = nums.size();
         int i=0;
         int j=0;
         long long  ans = 0;
         long long  prod = 1;
         while(j<n){
             prod = prod*nums[j];
             if(prod < k){
                ans += (j-i+1);
                j++;
             }
             else{
                while(i <= j && prod>=k){
                    prod = prod/nums[i];
                    i++;
                 }
                 if(prod<k)
                   ans+= j-i+1;
                 j++;
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends