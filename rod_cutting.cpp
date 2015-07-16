#include<iostream>

using namespace std;

//int price[] = {0, 3, 5, 8, 9, 10, 17, 17, 20};
int price[] = {1, 48, 72, 100,1};
int cost[6] = {0}; 

void rodCutting(void){
    int size = sizeof(price)/sizeof(price[0]);
    for(int i=1; i<size; i++){
        int q = cost[i];
        for(int j=0; j < i; j++){
            if (q < price[j] + cost[i-j]) {
                q = price[j] + cost[i-j];
            }
            cost[i] = q;
        }
    }
    
    for(int i=0; i<size; i++)
        cout<<cost[i]<<" ";
}


int main() {
    rodCutting();
    return 0;
}
