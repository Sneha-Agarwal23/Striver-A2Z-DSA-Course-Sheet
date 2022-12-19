//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	
	vector<int>AllPrimeFactors(int N) 
	{
	    vector<int> ans;
	    vector<int> prime(N+1, 1);
	    prime[0] = 0;
	    prime[1] = 0;
	    for(int i = 2; i*i <= N; i++)
	    {
	        for(int j = 2*i; j <= N; j = j+i)
	        {
	            prime[j] = 0;
	        }
	    }
	    for(int i = 2; i <= N; i++)
	    {
	        if(N%i == 0 && prime[i] == 1)
	            ans.push_back(i);
	    }
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends