//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        void fun(Node *r,int n,vector<Node *> &v,int f)
        {
            if(r==NULL)return;
            if(f==0)return;
            if(r->data==n)
            {
                f=0;
                v.push_back(r);
            }
            if(f==1)v.push_back(r);
            // cout<<r->data<<" ";
            if(f==1 and n<r->data)
            {
                fun(r->left,n,v,f);
            }
            else if(f==1 and n>r->data)
            {
                fun(r->right,n,v,f);
            }
            // if(f==0)v.pop_back();
        }
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            vector<Node *>v1;
            vector<Node *>v2;
            fun(root,n1,v1,1);
            fun(root,n2,v2,1);
            int i=v1.size();
            int j=v2.size();
            int in=0;
            int jn=0;
            // while(v1[i]!=v2[j])
            // {
            //     if(i!=0 and v1[i]->data>v2[j]->data)
            //     {
            //         i--;
            //     }
            //     else if(v1[i]->data==v2[j]->data)break;
            //     else if(j!=0 and v1[i]->data<v2[j]->data)
            //     {
            //         j--;
            //     }
            //     else if(i>j)
            //     {
            //         i--;
            //     }
            //     else
            //     {
            //         j--;
            //     }
            //     // break;
            // }
            Node *t=new Node(-1);
            while(in!=i and jn!=j)
            {
                if(v1[in]==v2[jn])t=v1[in];
                in++;
                jn++;
            }
            return t;
            
            
            return root;
        }

};


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends