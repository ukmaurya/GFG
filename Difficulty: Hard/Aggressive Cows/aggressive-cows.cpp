//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
     bool possible(vector<int>&stalls , int k ,  int mid ){
         int n = stalls.size();
         int count = 1;
         int prev = 0;
         for(int i=1;i<n;i++){
             if(stalls[i]-stalls[prev] >= mid){
                 count++;
                 prev = i;
             }
             
         }
         if(count>=k){
             return true;
         }
         return false;
     }
public:

    int solve(int n, int k, vector<int> &stalls) {
    
           
            int ans = -1;
            sort(stalls.begin() , stalls.end());
             int start = 0;
            int end = stalls[n-1] - stalls[0];
            while(start<= end){
                int mid = (start+end)/2;
                if(possible(stalls , k , mid)){
                    ans = mid ; 
                   start = mid+1;
                }
                else{
                   end = mid-1;
                }
            }
            return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends