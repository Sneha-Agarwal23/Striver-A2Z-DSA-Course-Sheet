//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* nextnode;
        while(head != NULL)
        {
            nextnode = head->next;
            head->next = prev;
            prev = head;
            head = nextnode;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        Node* tail = reverse(head);
        Node* temp = tail;
        while(temp != NULL)
        {
            if(temp->next == NULL && temp->data == 9)
            {
                temp->data = 10;
                break;
            }
            if(temp->data == 9)
            {
                temp->data = 0;
                temp = temp->next;
            }
            else
            {
                temp->data = temp->data + 1;
                break;
            }
        }
        return reverse(tail);
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
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends