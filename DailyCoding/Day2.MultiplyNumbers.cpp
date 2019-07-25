#include<bits/stdc++.h>
using namespace std;

/*

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product 
of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. 
If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

Solution. 
We declare tree arrays, the first is the result array, the second is left array, here we store the multiplication that we have
from index 0 to i, from left to right, the third array is the right array, we store the mult result from the size of the array
less one to 0, from right to left.
To fill the result array, the 0 position is the value of the right array at index 1, the (array size -1) position is the value
of the left array at the same index less one.
The other indexes of the array are filled multiplying left[i-1]*right[i+1] 

*/

vector<int> productos(vector<int> &nums){
	vector<int> r(nums.size());
	vector<int> izq(nums.size());
	vector<int> der(nums.size());
	int prod=1;
	for(int i=0;i<nums.size();i++){
		prod*=nums[i];
		izq[i]=prod;
	}
	prod=1;
	for(int i=nums.size()-1;i>=0;i--){
		prod*=nums[i];
		der[i]=prod;
	}
	for(int i=0;i<nums.size();i++){
		if(i==0){
			r[i]=der[i+1];
			continue;
		}
		if(i==nums.size()-1){
			r[i]=izq[i-1];
			continue;
		}
		r[i]=izq[i-1]*der[i+1];
	}
	return r;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	vector<int> res=productos(nums);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<"\n";
	return 0;
}