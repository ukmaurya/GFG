//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
     
 int res = 0;
        
        for(int i = 1; i<n+1; i++)
        {
          int j=i;
        
          while(j>0)
          {
            if(j%10 == 4)
             {
                res++;
                break;
             }
            j/=10;
          }
           
        }
    return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends