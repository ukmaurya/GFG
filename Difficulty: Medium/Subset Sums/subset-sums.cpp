//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void solve(int idx , vector<int>&arr , int sum , vector<int>&ans){
        int n = arr.size();
        if(idx>=n){
            ans.push_back(sum);
            return ;
        }
        
       solve(idx+1 , arr, sum+arr[idx] , ans);
       solve(idx+1 , arr , sum , ans);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        
        vector<int> ans;
        int sum=0;
        
        solve(0,arr,sum, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends