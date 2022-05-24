// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        long long int maximum_sum(vector<long long int>v)
    {
        int n = v.size();
        int prefix_sum[n];
        prefix_sum[0]=v[0];
        map<int , int> m;
        m[v[0]]=0;
        long long int max_sum =v[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + v[i];
            if(m.find(v[i])==m.end())

            {

                m[v[i]]=i;

            }

            else

            {

                int sum = prefix_sum[i]-prefix_sum[m[v[i]]]+v[i] ;

                if(sum>max_sum)

                max_sum = sum;

            }

            if(v[i]>max_sum)

            max_sum = v[i];

        }

        return max_sum;
    }
};

// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    vector<long long int>v(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    Solution ob;
	    long long int max_sum=ob.maximum_sum(v);
	    cout<<max_sum<<endl;
	}
	return 0;
}
  // } Driver Code Ends