//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    /*bool isPrime(int n)
    {
        bool flag = true;
        for(int i = 2; i <= n/2; i++)
        {
            if(n%i == 0)
                flag = false;
        }
        return flag;
    }*/
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> ans;
        vector<int> v(N+1, 1);
        for(int i = 2; i <= N; i++)
        {
            if(v[i] != 0)
            {
                ans.push_back(i);
                for(int j = 2*i; j <= N; j= j+i)
                {
                    v[j] = 0;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends