//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    bool static mycomp(pair<double,int>&p1 , pair<double , int>&p2){
        return p1.first>p2.first;
        
    }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double , int >> vw;
        for(int i=0;i<n;i++){
            vw.push_back({(1.0*arr[i].value/arr[i].weight ), i});
        }
        sort(vw.begin() , vw.end() , mycomp);
        
        double profit =0;
        for(int i=0;i<n;i++){
            if(w==0){
                break;
            }
            if(w-arr[vw[i].second].weight >= 0 ){
                w -= arr[vw[i].second].weight;
                profit += arr[vw[i].second].value;
            }
            else{
                profit += 1.0*w*(arr[vw[i].second].value/(double)arr[vw[i].second].weight); 
                break;
            }
        }
        
        return profit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends