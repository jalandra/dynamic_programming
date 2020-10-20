//https://www.geeksforgeeks.org/minimum-steps-minimize-n-per-given-condition/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include<climits>

class Solution{

	public:
	int *arr=0;
	int minSteps(int N) 
	{ 
	    if(!arr) {
	        arr = new int[N+1];
	    }
	    // Your code goes here
	    if(N==0 || N==1)
	        return 0;
	    int x=INT_MAX;
	    if(N%2 == 0) {
	       if(arr[N/2]) {
	         x = min(x,1+arr[N/2]);
	       }
	       else {
	         x = min(x,1+minSteps(N/2));
	       }
	    }
	    if(N%3 == 0) {
	       if(arr[N/3]) {
	         x = min(x,1+arr[N/3]);
	       }
	       else {
	         x = min(x,1+minSteps(N/3));
	       }
	    }
	    if(arr[N-1]) {
	        x = min(x, 1+arr[N-1]);
	    }
	    else {
	        x = min(x,1+minSteps(N-1));
	    }
	    arr[N] = x;
	    return arr[N];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
