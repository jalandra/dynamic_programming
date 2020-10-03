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
//DP
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
