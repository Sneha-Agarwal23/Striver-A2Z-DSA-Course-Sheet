//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) 
{
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        int sell = i, buy = i;
        while(i < n-1 && price[i] >= price[i+1])
        {
            i++;
        }
        buy = i;
        while(i < n-1 && price[i] <= price[i+1])
            i++;
        sell = i;
        if(sell - buy > 0)
        {
            cout<<"("<<buy<<" "<<sell<<")"<<" ";
            flag = true;
        }
    }
    if(flag == false)
        cout<<"No Profit";
    cout<<endl;
    
}