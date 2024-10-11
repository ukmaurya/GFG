//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        
        unordered_map<int , int> mp;
        int n = arr.size();
        int ans =0;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                ans = max(ans ,i- mp[arr[i]]);
            }
            else{
                mp[arr[i]]=i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends