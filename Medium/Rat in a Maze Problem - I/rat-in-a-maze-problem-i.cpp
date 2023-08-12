//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fun(int a,int b,int n,vector<vector<int>> &g,vector<string> &re,string s,vector<vector<int>> &vi)
    {
        if(a>=n or b>=n or a<0 or b<0 or g[a][b]==0)return;
        if(a==n-1 and b==n-1 and g[a][b]==1)
        {
            re.push_back(s);
            return;
        }
        if(vi[a][b]!=-1)return;
        vi[a][b]=1;
        fun(a-1,b,n,g,re,s+'U',vi);
        fun(a+1,b,n,g,re,s+'D',vi);
        fun(a,b-1,n,g,re,s+'L',vi);
        fun(a,b+1,n,g,re,s+'R',vi);
        vi[a][b]=-1;
        return;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vi(n,vector<int>(n,-1));
        string s="";
        vector<string>re;
        fun(0,0,n,m,re,s,vi);
        return re;
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends