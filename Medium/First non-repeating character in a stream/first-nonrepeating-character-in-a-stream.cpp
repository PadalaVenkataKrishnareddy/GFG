//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    map<char,int> m;
		    queue<char> q;
		    char ch='A';
		    string s="";
		    for(int i=0;i<a.size();i++)
		    {
		      if(m[a[i]]==0 and ch=='A')
		      {
		          s+=a[i];
		          m[a[i]]++;
		          q.push(a[i]);
		          ch=a[i];
		      }
		      else
		      {
		          if(m[a[i]]==0)q.push(a[i]);
		          m[a[i]]++;
		          
		          char c='E';
		          while(!q.empty())
		          {
		              char t=q.front();
		              if(m[t]!=1)q.pop();
		              else
		              {
		                  c=t;
		                  break;
		              }
		          }
		          if(c=='E')s+='#';
		          else s+=c;
		      }
		    }
		    return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends