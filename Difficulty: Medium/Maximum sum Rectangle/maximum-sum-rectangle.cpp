//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int LargestSumSub(vector<int>&arr){
        int n = arr.size();
        int sum =0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi = max(sum , maxi);
            if(sum<0){
                sum=0;
            }
            
        }
        return maxi;
    }
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
         
          int maxi =INT_MIN;
          // try to convert to 1d array
          for(int i=0;i<R;i++){
              vector<int> arr(C,0);
               for(int j=i;j<R;j++){
                for(int k=0;k<C;k++){
                    arr[k]=arr[k]+M[j][k];
                }
                maxi=max(maxi ,LargestSumSub(arr));
            }
          }
          return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends