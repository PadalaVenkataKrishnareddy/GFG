//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        k--;
        int i=0;
        while(v.size()!=1)
        {
            i=(i+k)%v.size();
            v.erase(v.begin()+i);
            
        }
        return v[0];
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends