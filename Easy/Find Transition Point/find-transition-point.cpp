//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int i=0;
    int j=n-1;
    int m;
    if(arr[0]==1)return 0;
    while(i<j)
    {
        m=(i+j)/2;
        // cout<<m<<" ";
        if(arr[m]==1 and arr[m-1]==0)return m;
        else if(arr[m]==0)
        {
            i=m+1;
        }
        else
        {
            j=m-1;
        }
    }
    if(arr[i]==0)return -1;
    return i;
}