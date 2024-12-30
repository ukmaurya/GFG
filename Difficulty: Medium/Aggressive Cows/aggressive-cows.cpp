//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
     bool poss(vector<int>&stalls , int k , int mid){
         int n = stalls.size();
         int count = 1; // placing the first cow at first stall
         int prev = stalls[0];
         for(int i=1;i<n;i++){
             if(stalls[i]-prev >= mid){
                 prev = stalls[i];
                 count++;
             }
         }
         if(count >= k){
             return true;
         }
         return false;
         
     }
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

            // max of min => binary search problem 
            int n = stalls.size();
            sort(stalls.begin() , stalls.end());
            int start = 0;
            int end  = (stalls[n-1] - stalls[0]);
            int ans = -1;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(poss(stalls ,k ,mid)){
                    ans = mid;
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
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends