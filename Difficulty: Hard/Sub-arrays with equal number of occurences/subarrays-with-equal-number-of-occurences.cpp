//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>&nums, int x, int y) {
        // code here
        
      // logic : change x to 1. and y to -1  and remaining element  to 0
      
      int n = nums.size();
      for(int i=0;i<n;i++){
          if(nums[i]==x){
              nums[i] = 1;
          }
          else if(nums[i]==y){
              nums[i]= -1;
          }
          else{
              nums[i]=0;
          }
      }
    // now apply logic of # of subarray with sum k 
       int k = 0;
       unordered_map<int, int> mp; // preSum , frequency 
        mp[0]=1;
        int preSum =0;
      
        int count=0;
        for(int i=0;i<n;i++){
             preSum+=nums[i];
             if(mp.find(preSum-k)!= mp.end()){
                  count+=mp[preSum-k];
             }
             mp[preSum]++;
        }
        return count;
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
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends