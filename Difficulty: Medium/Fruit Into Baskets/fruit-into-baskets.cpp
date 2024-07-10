//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        // second condition is showing that we have to take fruits in contiguous manner 
        // substring concept may be used 
        unordered_map<int , int > mp;
        int i=0;
        int j=0;
        int ans =0;
        while(j<N){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                ans = max(ans , j-i+1); // after updating ans increment the j pointer 
                j++;
                
            }
            else{
                while( mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
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
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends