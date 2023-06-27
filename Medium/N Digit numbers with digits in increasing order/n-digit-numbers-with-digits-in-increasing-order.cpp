//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void fun(int n,string s,vector<string> &re,int ind)
    {
        if(s.size()==n)
        {
           
            re.push_back(s);
           
            return;
        }
        for(int i=ind;i<10;i++)
        {
                fun(n,s+to_string(i),re,i+1);
        }
    }
    vector<int> increasingNumbers(int n)
    {
        // Write Your Code here
        vector<string> re;
        
        if(n!=1)fun(n,"",re,1);
        else fun(n,"",re,0);
        for(auto it:re)
        {
            cout<<it<<" ";
        }
        return {};
        
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends