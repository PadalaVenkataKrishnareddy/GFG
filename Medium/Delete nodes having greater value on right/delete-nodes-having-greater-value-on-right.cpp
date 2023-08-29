//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        vector<int> v;
        Node *h=head;
        while(h)
        {
            v.push_back(h->data);
            h=h->next;
        }
        vector<int> r;
        int n=v.size();
        r.push_back(v[n-1]);
        int ma=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]>=ma)
            {
                ma=v[i];
                r.push_back(ma);
            }
        }
        reverse(r.begin(),r.end());
        Node *he=new Node(r[0]);
        Node *t=he;
        for(int i=1;i<r.size();i++)
        {
            Node *el=new Node(r[i]);
            he->next=el;
            he=he->next;
        }
        return t;
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends