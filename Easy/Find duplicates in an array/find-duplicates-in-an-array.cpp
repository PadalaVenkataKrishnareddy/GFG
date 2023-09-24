//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        // vector<int> v;
        set<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)m[arr[i]]++;
        // vector<int> v{s.begin(),s.end()};
        for(auto it:m)
        {
            if(it.second>1)v.insert(it.first);
        }
        vector<int> s{v.begin(),v.end()};
        if(s.size()==0)return {-1};
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends