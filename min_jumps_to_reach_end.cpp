https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

#include<iostream>
#include<vector>
#include<climits>

//recursive
using namespace std;
int minJumps(vector<int> &arr, int index, int end, int jumps) {
    static int jumps_min = INT_MAX;
    if(index + arr[index] >= arr.size() -1) {
        return jumps+1;
    }
    else if(arr[index] == 0) {
        return jumps_min;
    }
    for(int i=index+1; i<=end; ++i) {
        int j = minJumps(arr, i, i+arr[i], jumps+1);
        if(j<jumps_min)
            jumps_min = j;
    }
    return jumps_min;   
}
int main()
{
 //arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}	//code
 int t;
 cin>>t;
 while(t--) {
    int n;
    cin>>n;
    vector<int> arr;
    arr.reserve(n);
    int elem;
    while(n--) {
        cin>>elem;
        arr.push_back(elem);
    }
    if(arr[0] == 0)
        cout<<"-1"<<endl;
    else
        cout<<minJumps(arr, 0, arr[0], 0)<<endl;
    arr.clear();
 }
 return 0;
}
///DP
/DP
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int minJumps(vector<int> &arr, int index, int end, int jumps, vector<int> &jumps_dp) {
    static int jumps_min = INT_MAX;
    if(arr[index] == 0) {
        return jumps_dp[index];
    }
    else if(index + arr[index] >= arr.size() -1) {
        jumps_dp[index] = jumps+1;
        return jumps_dp[index];
    }
    
    for(int i=index+1; i<=end; ++i) {
        if(jumps_dp[i] != INT_MAX && jumps_dp[i] < jumps_dp[index]) {
            jumps_dp[i] = jumps_dp[index];
        }
        else {
            jumps_dp[i] = minJumps(arr, i, i+arr[i], jumps+1, jumps_dp);
        }
        if(jumps_dp[index] > jumps_dp[i])
            jumps_dp[index] = jumps_dp[i];
    }
    /*for(int i=0; i<arr.size();++i)
        cout<<jumps_dp[i]<<" ";
    cout<<end;*/
    return jumps_dp[index];
}

int main()
{
 //arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}	//code
 int t;
 cin>>t;
 while(t--) {
    int n;
    cin>>n;
    vector<int> arr;
    vector<int> jumps_dp;
    arr.reserve(n);
    jumps_dp.reserve(n);
    int elem;
    while(n--) {
        cin>>elem;
        arr.push_back(elem);
        jumps_dp.push_back(INT_MAX);
    }
    if(arr[0] == 0)
        cout<<"-1"<<endl;
    else {
        //jumps_dp[0] = 1;
        cout<<minJumps(arr, 0, arr[0], 0, jumps_dp)<<endl;
        //cout<<jumps_dp[0]<<endl;
    }
    /*cout<<"jumps: ";
    for(int i=0; i<arr.size();++i)
        cout<<jumps_dp[i]<<" ";
    */
    arr.clear();
    jumps_dp.clear();
 }
 return 0;
}
