//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
         // since it contains -ve elements => sliding window will fails
         
         int preSum =0;
         map<int, int > mp;
         
         mp[0]=-1;
         int ans= 0;
         for(int i=0;i<n;i++){
             preSum+=A[i];
             int req = preSum; // preSum-req ie preSum-0 = preSum;
             
            if(mp.find(req) != mp.end()){
                  
                  int len = i- mp[req];
                  ans = max(len , ans);
             }
             if(mp.find(preSum)==mp.end()) // this condition is very important since array contains negative numbers 
               mp[preSum]=i;
         }
         return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends