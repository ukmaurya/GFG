//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
      
        // using merging technique o(n+m) time
        int n = arr1.size();
        int m = arr2.size();
        
        int count =0;
        int l = 0;
        int r = 0;
        int ans = -1;
        while(l<n && r<m){
            count++;
            if(arr1[l]<arr2[r]){
                if(count==k){
                    ans= arr1[l];
                    return ans;
                }
                l++;
            }
            else{
                if(count==k){
                    ans= arr2[r];
                    return ans;
                }
                r++;
                
            }
        }
        while(l<n){
             count++;
            if(count==k){
                ans= arr1[l];
                 return ans;
            }
                l++;
        }
        
          while(r<m){
             count++;
            if(count==k){
                ans= arr2[r];
                 return ans;
            }
                r++;
        }
        
      
      
      return ans;
      
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends