This question was found at https://www.careercup.com/question?id=5750868554022912

Suppose a row of parking lot with n spots, one of them is empty and n-1 spots are occupied with cars.
Only one operation is allowed: move one car from its position to the empty spot.
Given a initial order of cars and a final order, output steps needed to convert initial order to final oder with that operation. 

#include<iostream>
#include<map>
 
using namespace std;
 
int getPos(int in_arr[], int size, int elem) {
  for(int i=0; i<size; ++i) {
    if(in_arr[i] == elem)
      return i;
  }
}
 
void swap(int in_arr[], int to, int from, int &moves) {
  if(to != from) {
    int temp = in_arr[to];
    in_arr[to] = in_arr[from];
    in_arr[from] = temp;
    ++moves;
  }
}
 
int countMoves(int in_arr[], int out_arr[], int size) {
	map<int, int> in_arr_map;
  for(int i=0; i<size; ++i) {
    in_arr_map[in_arr[i]] = i;
  }
  int moves=0;
	for(int i=0; i<size; ++i) {
		if(in_arr[i] != out_arr[i] && in_arr[i] != -1) {
    	  int pos = getPos(in_arr, size, -1);
        swap(in_arr,i,pos, moves);
        pos = getPos(in_arr, size, out_arr[i]);
        swap(in_arr,i,pos,moves);
    }
	}
	return moves;
}
 
int main(){
	int in_arr[] = {1,2,3,-1,4,5};
	//int out_arr[] = {5,1,-1,3,2,4};
	int out_arr[] = {1,2,3,4,5,-1};
	cout<<countMoves(in_arr, out_arr, 6);
	return 0;
}
