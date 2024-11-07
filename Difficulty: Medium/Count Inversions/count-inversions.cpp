//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int merge(int s , int mid , int e , vector<int>&arr){
        vector<int> temp;
        int inversion =0;
        
        
        
        int i=s;
        int j = mid+1;
         while(i <= mid && j<=e){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                inversion += (mid-i+1);
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=e){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i=0;i< temp.size();i++){
            arr[i+s] = temp[i];
            
        }
        return inversion;
        
    }
    int mergesort(int i , int j , vector<int>&arr){
        if(i>=j)
          return 0;
        int mid = (i+j)/2;
        int ans = 0;
        ans += mergesort(i,mid,arr);
        ans += mergesort(mid+1 , j , arr);
        ans += merge(i,mid,j , arr);
        return ans;
    }
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        return mergesort(0,n-1 , arr);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends