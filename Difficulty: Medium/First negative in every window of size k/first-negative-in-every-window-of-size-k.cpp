//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                  // ideal structure                                
                    vector<long long > ans;
                    int i =0;
                    int j =0;
                    vector<long long > negatives;
                    while(j<N){ // loop termination condition 
                       
                       if(A[j]< 0 ) // calculation part ie storing the negative elements 
                        {
                           negatives.push_back(A[j]); 
                        }
                        
                        // condition part
                        if(j-i+1<K){
                            j++;
                        }
                        else if( j-i+1 == K ){ // required size
                          // two work is done here
                          // 1) calculation that leads to answer 
                          // 2) slide the window 
                          if(negatives.size()==0){ 
                              ans.push_back(0);
                          }
                          else {
                              ans.push_back(negatives.front());
                               if(negatives.front()==A[i]){
                                   negatives.erase(negatives.begin());
                               }
                          }
                          
                          // slide the window 
                         
                          i++;
                          j++;
                          
                            
                        }
                        
                    }
                    return ans;
                                                 
 }