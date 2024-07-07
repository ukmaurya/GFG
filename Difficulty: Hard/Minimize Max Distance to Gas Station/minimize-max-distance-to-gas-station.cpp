//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
   bool isPossible(double mid , vector<int>&stations , int k ){
        int n = stations.size();
        int count=0;
        for(int i=0;i<n-1;i++){
           int diff = stations[i+1] - stations[i];
           int num = diff/mid;
           if(num == (stations[i+1] - stations[i])/mid){
               num = num-1;
           }
           count = count+num;
            
        }
        if(count<=k){
            return true;
            
        }
        return false;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
          
          
         int maxi =INT_MIN;
         int n = stations.size();
         for(int i=0;i<n-1;i++ ){
            maxi = max(maxi , stations[i+1]-stations[i]);
         }
         double start = 0;
         double end = maxi ;
         double ans=-1;
          while(end-start > 1e-6){
             double mid = start + (end-start)/2.0;
              if(isPossible(mid , stations , k)){
                 
                 end = mid;
                  ans = mid;
              }
              else{
                 
                   start = mid;
              }
          }
          
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends