//https://www.geeksforgeeks.org/minimum-cost-to-fill-given-weight-in-a-bag/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		
	int minCostImpl(int cost[], int N, int W, int totalCost=0) 
	{ 
        static int minCost = INT_MAX;
        if(W == 0)
            return min(totalCost, minCost);
        else {
            if(N<1 || W < 0) {
                return  INT_MAX;
            }
            if(cost[N-1] == -1) {
                return minCostImpl(cost, N-1, W, totalCost);
            }
            int local_min = min(minCostImpl(cost, N, W-N, totalCost+cost[N-1]),
                            min(minCostImpl(cost, N-1, W-N, totalCost+cost[N-1]),
                                minCostImpl(cost, N-1, W, totalCost))
                                );
            if(local_min < minCost)
                minCost = local_min;
            return minCost;
        }
	}
	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        int ret = minCostImpl(cost, N, W, 0);
        if(ret == INT_MAX) {
            return -1;
        }
        else
            ret;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
