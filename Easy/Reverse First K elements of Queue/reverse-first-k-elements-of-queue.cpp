//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        vector<int> v;
        while(q.empty()!=1)
        {
            int h=q.front();
            v.push_back(h);
            q.pop();
        }
        for(int i=k-1;i>=0;i--)
        {
            q.push(v[i]);
        }
        for(int i=k;i!=v.size();i++)
        {
            q.push(v[i]);
        }
        return q;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends