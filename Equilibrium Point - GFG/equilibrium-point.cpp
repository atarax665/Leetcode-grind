// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
        // two pointer method
        int left = 0, right = n - 1;
        long frontSum = 0, backSum = 0;
        while(left < right) {
            if(frontSum > backSum)
            {
                backSum = backSum + arr[right];
                right = right - 1;
            }
            else
            {
                frontSum = frontSum + arr[left];
                left = left + 1;
            }
        }
        
        if(frontSum != backSum) return -1;
        
        return right + 1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends