//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set<int> s;
        Node* temp1 = head1;
        Node* temp2 = head2;
        vector<int> v;
        while(temp2 != NULL)
        {
            s.insert(temp2->data);
            temp2 = temp2->next;
        }
        while(temp1 != NULL)
        {
            if(s.find(temp1->data) != s.end())
            {
                v.push_back(temp1->data);
            }
            temp1 = temp1->next;
        }
        Node* prev = new Node(0);
        Node* head =  prev; 
        for(int i = 0; i < v.size(); i++)
        {
            Node* newnode = new Node(v[i]);
            head->next = newnode;
            head = head->next;
        }
        return prev->next;
    
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends