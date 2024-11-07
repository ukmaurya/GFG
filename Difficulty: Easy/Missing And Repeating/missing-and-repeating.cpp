//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int xorr = 0;
        for(int i=0;i<n;i++){
            xorr = xorr^arr[i];
            xorr = xorr^(i+1);
        }
        
        int bit = 0;
        int count =0;
        while(xorr){
            if(xorr&1){
                bit = count;
                break;
            }
            count++;
            xorr = xorr>>1;
        }
        
        int val1 , val2;
        val1 = val2=0;
        for(int i=0;i<n;i++){
            if(arr[i]&(1<<bit)){
                val2 = val2^arr[i];
            }
            else{
                val1 = val1^arr[i];
            }
        }
         
        for(int i=1;i<=n;i++){
            if(i&(1<<bit)){
                val2 = val2^i;
            }
            else{
                val1 = val1^i;
            }
        }
        
        // val 1 and val2 contains the element
        int flag =-1;
        for(int i=0;i<n;i++){
            if(arr[i] == val1){
                flag = 1;
                break;
            }
        }
        if(flag == -1){
           return  {val2 , val1};
        }
        
       return {val1 , val2}; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends