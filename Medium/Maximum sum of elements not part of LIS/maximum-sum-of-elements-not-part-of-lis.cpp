//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSumLis(int Arr[], int n) {
         
         // using tabulation method
         vector<int> dp(n,1); // store the lis size ending at that element
         vector<int> hash(n);
         for(int i=0;i<n;i++){
             hash[i]=i;
         }
        
         int maxi =INT_MIN;
        for(int i=0;i<n;i++){
             for(int j=i-1;j>=0;j--){
                 if(Arr[i]>Arr[j]&&dp[i]<dp[j]+1){
                     dp[i] = dp[j]+1;
                     hash[i] = j;
                 }
               
                }
                if(maxi < dp[i]){
                     maxi = dp[i];
               }
             
         }
      
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=Arr[i];
        }
        // There may be the cases where many LIS of same length exist 
        int lisSum = INT_MAX;
       
        for(int i=0;i<n;i++){
             int res=0;
            if(dp[i]==maxi){
                int index = i;
                while(hash[index]!=index){
                    res += Arr[index];
                    index = hash[index];
                }
                res+= Arr[index];
                lisSum = min(lisSum , res);
            }
          
        }
        return sum-lisSum;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for (int i = 0; i < n; i++) cin >> Arr[i];
        Solution obj;
        cout << obj.maxSumLis(Arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends