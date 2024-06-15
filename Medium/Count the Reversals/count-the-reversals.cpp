//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
       int n = s.size();
       if(n&1)
         return -1;
       stack<char> st;
       for(int i=0;i<n;i++){
           if(s[i]=='{')
           {
               st.push('{');
           }
           else{
               if(st.size()>0 && st.top()=='{')
                 st.pop();
               else{
                   st.push('}');
               }     
           }
       }
       int size = st.size();
       int count=0;
       while(!st.empty()){
           if(st.top()=='{')
             count++;
         st.pop();     
       }
       int ans = size/2+count%2;
      
       return ans;
}