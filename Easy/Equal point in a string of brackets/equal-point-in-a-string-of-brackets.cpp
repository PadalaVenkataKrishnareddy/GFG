//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int findIndex(string str) {
        // Your code goes here   
        int c=0;
        int io=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==')')c++;
            else io++;
            
        }
        if(io==0)return str.size();
        if(c==0)return 0;
        int o=0;
        for(int i=0;i<str.size();i++)
        {
            if(o==c)return i;
            if(str[i]=='(')o++;
            else c--;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.findIndex(s)<<endl;
	}
}
// } Driver Code Ends