//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
       if (s > 9 * d) {
            return "-1";
        }
         string st ="";
        for(int i=d-1;i>=0;i--){
            
            for(int j=9;j>=0;j--){
                
                if(i != 0){
                    if(s - j > 0){
                        st += j +'0';
                        s = s-j;
                        break;
                    }
                }
                else{
                    st += s +'0';
                    break;
                }
            }
        }
        reverse(st.begin(),st.end());
        return st;
      /* string ans = "";
        int req = d;
       for(int i=0;i<d-1;i++){
          
           for(int j=9;j>=;j--){
             //  cout<<ceil(1.0*s/j)<<endl;
               if((ceil(1.0*s/j))==req){
                    ans += to_string(j);
                    s=s-j;
                    req--;
                    break;
               }
               else{
                   continue;
                }
           }
       }
        ans +=to_string(s);
        reverse(ans.begin() , ans.end());
        return ans; */
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends