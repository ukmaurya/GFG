//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool possible(vector<int>&stations , double mid , int k ){
        int n = stations.size();
        int atleastStations = 0;
        for(int i=1;i<n;i++){
            double diff = stations[i]-stations[i-1];
            atleastStations += floor(diff/mid*1.0);
        }
        if(atleastStations<=k){
            return true;
        }
        return false;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
         
        //  priority_queue<double> pq;
        //  int n = stations.size();
        //  for(int i=1;i<n;i++){
        //      pq.push(stations[i]-stations[i-1]);
        //  }
       
        //  while(k--){
        //      double t = pq.top();
        //      pq.pop();
        //      pq.push(t/2);
        //      pq.push(t/2);
           
             
        //  }
        //  double ans = INT_MIN;
        //  while(!pq.empty()){
        //      ans = max(ans , pq.top());
        //      pq.pop();
        //  }
        //  return ans;
        
        // above method is wrong check example -- distance is 1 to 12 and u want to put 2 more station 
   
         int maxi = 0;
         int n = stations.size();
         for(int i=0;i<n-1;i++){
              maxi = max(maxi , stations[i+1]-stations[i]);
         }
         double start = 0;
         double end = maxi;
         double ans =-1;
         while(end-start > 1e-6){
             double mid = start-(start-end)/2.0;
             if(possible(stations , mid ,k)){
                 ans = mid;
                 end = mid; // since double 
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