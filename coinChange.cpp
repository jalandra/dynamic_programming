/*
It gives the minimum number of change of coins needed
to make the desired sum
*/

#include<iostream>

using namespace std;
 
int minNumCoinsChange(int coins[], int sum){
    int length = sizeof(coins)/sizeof(coins[0]);
    int *temp = new int[sum+1];
    int numberOfCoins = 0;
    
    for(int i=1; i<=sum; i++){
        for(int j=0; j<length && j<=i; j++){
            if(coins[j] > i)
            temp[i] temp[i] = min(1+temp[i-coins[j]], i/coins[j]);
        }
    }
    int ret = temp[sum];
    delete []temp;
    return ret;
}


int main(void){
    int coins[] = {1,5,6,8};
    int sum = 10;
    cout<<minNumCoinsChange(coins,sum)<<endl;
    return 0;
}
