//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int search(int in[],int n, int curr)
    {
        for(int i = 0;i < n;i++)
        {
            if(in[i] == curr)
                return i;
        }
        return -1;
    }
    Node* build(int in[],int pre[],int &preorderIndex,int start,int end,int n)
    {
        if(start > end || preorderIndex >= n)
        {
            return NULL;
        }
        int curr = pre[preorderIndex];
        preorderIndex++;
        Node* root = new Node(curr);
        int pos = search(in,n,curr);
        root->left = build(in,pre,preorderIndex,start,pos-1,n);
        root->right = build(in,pre,preorderIndex,pos+1,end,n);
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex = 0;
        return build(in,pre,preorderIndex,0,n-1,n);
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends