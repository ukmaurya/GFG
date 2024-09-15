//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
       
           sort(A.begin() , A.end() , greater<int>());
           sort(B.begin() , B.end() , greater<int>());
           set<pair<int, int >> st;
           vector<int> ans;
           priority_queue<pair<int, pair<int,int >>> maxh;
           maxh.push({A[0]+B[0],{0,0}});
           st.insert({0,0});
           for(int i=0;i<K;i++){
               auto it = maxh.top();
               maxh.pop();
               ans.push_back(it.first);
               int a = it.second.first;
               int b = it.second.second;
               if(a+1<A.size() && st.find({a+1,b}) ==st.end() ){
                   maxh.push({A[a+1]+B[b],{a+1,b}});
                   st.insert({a+1,b});
               }
               if(b+1<B.size() && st.find({a,b+1}) ==st.end()){
                    maxh.push({A[a]+B[b+1],{a,b+1}});
                    st.insert({a,b+1});
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends