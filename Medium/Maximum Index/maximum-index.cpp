//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int lmi[n];
        int rma[n];
        lmi[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]<lmi[i-1])
            {
                lmi[i]=arr[i];
            }
            else
            {
                lmi[i]=lmi[i-1];
            }
        }
        rma[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>rma[i+1])
            {
                rma[i]=arr[i];
            }
            else
            {
                rma[i]=rma[i+1];
            }
        }
        int c=0;
        int i=0;
        int j=0;
        while(i<n and j<n)
        {
           if(lmi[i]>rma[j])
           {
               
               i++;
            //   j=0;
            //   c=max(c,j-i)
           }
           else
           {
               c=max(c,j-i);
               j++;
           }
        }
        return c;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends