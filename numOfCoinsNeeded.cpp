/*
It gives the maximum ways by which a sum can achieved using the 
given combination of coins
*/
#include<iostream>

using namespace std;
 
int numOfWaysToGetSum(int coins[], int sum){
    int length = sizeof(coins)/sizeof(coins[0]);
    int *temp = new int[sum+1];
    
    for(int i=1; i<=sum; i++){
        for(int j=0; j<length && j<i; j++){
            if(i<coins[j])
                temp[i] = 0;
            else
                temp[i] = max(1+temp[i-coins[j]], temp[i]);
        }
    }
    int ret = temp[sum];
    delete []temp;
    return ret;
}


int main(void){
    int coins[] = {2,3};
    int sum = 10;
    cout<<numOfWaysToGetSum(coins,sum)<<endl;
    return 0;
}
