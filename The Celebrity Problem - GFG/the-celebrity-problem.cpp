// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        //push all person into stack
        for(int i=0; i<n ; i++){
            st.push(i);
        }
        while(st.size()>1){
            int i=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            //if ith prsn knows jth => i is not celebrity
            if(M[i][j] == 1){
                //i should be popped; and j should be pushed
                st.push(j);
            }
            else{
                //jth person doesn't known by ith => j isn't celebrity
                st.push(i);
            }
        }
        //Now we have potential celebrity in stack...which to be check in it's 
        //corresponding rows and columns
        int pot = st.top();
        // st.pop();
        for(int i=0;i<n ; i++){
            //if any ith person doesn't knows potentioal celebrity or any potential
            // celebrity knows any ith person => potential celebrity isn't celebrity 
            if(i!=pot){
                if(M[i][pot] == 0 || (M[pot][i]==1 && i != pot)){
                    return -1;
                }
            }
            
        }
        //else ...potential celebrity is our celebrity
        return pot;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends