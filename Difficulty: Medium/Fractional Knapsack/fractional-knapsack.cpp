//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    bool static cmp(pair<double , int >&p1 , pair<double , int >&p2){
        return p1.first > p2.first;
    }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          
          vector<pair<double , int >> ratio;
          int n = val.size();
          for(int i=0;i<n;i++){
              ratio.push_back({(val[i]*1.0)/wt[i] , i});
          }
          sort(ratio.begin() , ratio.end(),cmp);
          double profit=0;
          for(int i=0;i<n;i++){
              int index = ratio[i].second;
              if(capacity<=0)
                break;
              if(capacity >= wt[index]){
                  capacity -= wt[index];
                  profit += val[index];
              }
              else{
                  profit += ((val[index]*1.0)/wt[index])*capacity;
                  capacity = 0;
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
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends