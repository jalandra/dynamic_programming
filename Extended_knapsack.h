//https://www.geeksforgeeks.org/extended-knapsack-problem/
    
#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;


int maxProfitImpl(int cost[], int profit [], int N, int W, int k, int totalProfit) 
{
    static int maxPro = INT_MIN;
    if(W == 0) {
      if(k <=0)
        return INT_MIN;
      else
        return max(totalProfit, maxPro);
    }
    else {
        if(N<1 || W < 0 || k==0) {
            return  INT_MIN;
        }
        int local_max = max(maxProfitImpl(cost, profit, N, W-cost[N-1], k-1, totalProfit+profit[N-1]),
                        max(maxProfitImpl(cost, profit, N-1, W-cost[N-1], k, totalProfit+profit[N-1]),
                            maxProfitImpl(cost, profit, N-1, W, k, totalProfit))
                            );
        if(local_max > maxPro)
            maxPro = local_max;
        return maxPro;
    }
}
    
int maxProfit(int cost[], int profit[], int N, int W, int k) 
{
    return maxProfitImpl(cost, profit, N, W, k, 0);
}



int main()
{
     /*int N = 5;
     int P[] = {2, 7, 1, 5, 3};
     int C[] = {2, 5, 2, 3, 4};
     int W = 8, K = 2;
    */
    int N = 5;
    int P[] = {2, 7, 1, 5, 3};
    int C[] = {2, 5, 2, 3, 4};
    int W = 9, K = 2;
    cout<<maxProfit(C, P, N, W, K);
    return 0;
}









