//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void fun(int ind,string s,vector<string> &re,vector<int> &vi,string st)
    {
        if(st.size()==s.size())
        {
            // cout<<st<<" ";
            re.push_back(st);
            return;
        }
        if(ind==s.size())return;
        for(int i=0;i<s.size();i++)
        {
            if(vi[i]==0)
            {
                vi[i]=1;
                // cout<<s[i]<<" ";
                fun(ind,s,re,vi,st+s[i]);
                
                vi[i]=0;
            }
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> re;
        vector<int> vi(S.size()+1,0);
        string s="";
        fun(0,S,re,vi,s);
        // return {};
        sort(re.begin(),re.end());
        return re;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends