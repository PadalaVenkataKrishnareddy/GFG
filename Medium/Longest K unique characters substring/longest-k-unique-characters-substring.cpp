//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    map<char,int> m;
    int i=0,j=0,ma=-1;
    int n=s.size();
    while(i<n and j<n)
    {
        m[s[j]]++;
        
        if(m.size()>k)
        {
           m[s[i]]--;
           if(m[s[i]]==0)m.erase(s[i]);
           i++;
        }
        if(m.size()==k)
        {
            ma=max(ma,j-i+1);
        }
        j++;
        
    }
   
    return ma;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends