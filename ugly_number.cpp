#include<iostream>
using namespace std;

void findNthUglyNum(int n) {
	int ugly[n]; 
	int idx,idx2,idx3,idx5;
	idx=0;
	idx2=idx3=idx5=0;
	ugly[0] = 1;
	while(idx<n) {
		int num2 = ugly[idx2]*2; //factor of 2
		int num3 = ugly[idx3]*3; //factor of 3
		int num5 = ugly[idx5]*5; //factor of 5
		ugly[++idx] = std::min(std::min(num2, num3), num5);
		if(ugly[idx] == num2)
			++idx2;
		if(ugly[idx] == num3)
			++idx3;
		if(ugly[idx] == num5)
			++idx5;
	}
	for(auto i : ugly) {
		cout<<i<<" ";
	}
}

int main() {
	int n;
	cin>>n;
	findNthUglyNum(n);
	return 0;
}
