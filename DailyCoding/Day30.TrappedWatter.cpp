#include<bits/stdc++.h>
using namespace std;

/*
You are given an array of non-negative integers that represents a two-dimensional elevation map where each element 
is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index 
(we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.

Solution.
For the givin difficult we need to get the answer in O(n) time and O(1) space, so we only need to store a pointer that starts
from the left and a pointer that stats from the right, then we need to keep the maximum of the left and the maximum of the right
and for every value if the left pointer is less than the right pointer we add to the answer the result of max_left-arr[i].
If the right pointer is less, we add to the answer max_right-arr[i] 
*/

int TrappedWatter(vector<int> &walls){
	int izq=0,der=0;
	int lo=0,hi=walls.size()-1;
	int water=0;
	while(lo<hi){
		if(walls[lo]<walls[hi]){
			izq=max(walls[lo],izq);
			water+=izq-walls[lo];
			lo++;
		}
		else{
			der=max(walls[hi],der);
			water+=der-walls[hi];
			hi--;
		}
	}
	
	return water;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<TrappedWatter(arr)<<"\n";
	return 0;
}