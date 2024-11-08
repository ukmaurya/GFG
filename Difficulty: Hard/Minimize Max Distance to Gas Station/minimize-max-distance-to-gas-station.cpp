//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool isposs(vector<int>&stations , int k , double mid){
        int n = stations.size();
        int count = 0;
        for(int i=1;i<n;i++){
            double diff = (stations[i]-stations[i-1]);
            double temp = floor(diff/mid*1.0);
            count += temp;
         }
        if(count<=k){
            return true;
        }
        return false;
        
    }
  public:
    double findSmallestMaxDist(vector<int>&stations, int k) {
        // Code here
        int n = stations.size();
        double ans = -1.0;
        double start = 0.0;
        double end = 0.0;
        for(int i=1;i<n;i++){
            end = max(end , (1.0*stations[i]-1.0*stations[i-1]));
        }
        
        while(end-start > 1e-6 ){
            double mid = (start +end)/2.0;
            if(isposs(stations , k , mid)){
                ans = mid;
                end = mid; // since double since many points may be left 
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
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends