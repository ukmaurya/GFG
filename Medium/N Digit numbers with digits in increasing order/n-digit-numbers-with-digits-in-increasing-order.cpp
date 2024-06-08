//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void solve(int n , string &s , vector<int>&ans ){
        if(n==0){
            int num = stoi(s);
            ans.push_back(num);
            return;
        }
        for(int i=1;i<=9;i++){
            if(s.empty()||(s.back()-'0') < i){
                s=s+char(i+'0');
                solve(n-1,s,ans);
                s.pop_back();
                
            }
        }
    }
  public:
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        vector<int> ans;
        if(n==1){
            for(int i=0;i<=9;i++){
                ans.push_back(i);
            }
            return ans;
        }
        string s ="";
        solve(n,s,ans);
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
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends