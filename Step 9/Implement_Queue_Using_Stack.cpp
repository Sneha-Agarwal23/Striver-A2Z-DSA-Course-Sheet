//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x)
    {
        while(!input.empty())
        {
            int x = input.top();
            output.push(x);
            input.pop();
        }
        output.push(x);
        while(!output.empty())
        {
            int x = output.top();
            input.push(x);
            output.pop();
        }
    }

    int dequeue() 
    {
        if(input.empty())
            return -1;
        
        int x = input.top();
        input.pop();
        return x;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends