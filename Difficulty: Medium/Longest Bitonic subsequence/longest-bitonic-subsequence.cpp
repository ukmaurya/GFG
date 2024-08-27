//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
          
          vector<int> far(n,1);
          vector<int> back(n,1);
          
          for(int i=0;i<n;i++){
              for(int j=i-1;j>=0;j--){
                  if(nums[j]<nums[i] && 1+far[j]>far[i]){
                      far[i] = 1+far[j];
                }
              }
          }
          
          // for backwards 
          for(int i=n-1;i>=0;i--){
              for(int j = i+1;j<n;j++){
                  if(nums[i]>nums[j] && back[i]<back[j]+1){
                      back[i] = back[j]+1;
                  }
              }
          }
          
         
          int maxi = 0;
          for(int i=0;i<n;i++){
              if(far[i]==1 || back[i]==1)
                continue;
              maxi = max(maxi , far[i]+back[i]-1);
          }
         
          return maxi;
         
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends