//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int e=0;
	    int o=0;
	    int f=1;
	    for(int i=s.size()-1;i>=0;i--)
	    {
	        if(i%2!=0)
	        {
	            if(s[i]=='1')e++;
	        }
	        else
	        {
	            if(s[i]=='1')o++;
	        }
	    }
	    if(e==o)return 1;
	    else if((e!=0 and o==0) or (e==0 and o!=0) or (abs(e-o)%3==0))
	    {
	        return 1;
	    }
	    else return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends