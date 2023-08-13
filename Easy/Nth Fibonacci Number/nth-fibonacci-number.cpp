//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        if(n<=2)return 1;
        int a=1;
        int b=1;
        int c;
        n=n-2;
        int m=1000000007;
        for(int i=0;i<n;i++)
        {
            c=(a+b)%m;
            a=b%m;
            b=c%m;
        }
        return c%m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends