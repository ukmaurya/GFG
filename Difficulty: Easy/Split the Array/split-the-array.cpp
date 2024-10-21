//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        
        // as of now , we are unable to apply dp since we are not able to represent subset 2
        // in terms of subset 1
        
        //  g1^g2 = 0 => (a1^a2....)^(b1^b2...)=0 will be zero , we need to create the subgroup 
        
        int xorr = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            xorr = xorr^arr[i];
        }
        if(xorr!=0)
         return 0;
         
        int ans =( pow(2,n)-2 )/2; // exclude the {} {1,2,3} and {1,2,3}{}
        // divide by 2 since every group is counted twice 
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends