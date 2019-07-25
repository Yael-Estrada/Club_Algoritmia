#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5

Solution.
Creating two auxiliar counters, one for the max sum including the current element and one for the max sum excluding the
current element, so for each element in the array we test both
include= exclude+ actual position value (because we cant take contiguous values)
exclude=max(include,exclude)
at the end of the loop we return the maximum between this two values.
*/

int maxSum(vector<int> &arr){
	int inc=0,exc=0;
	for(int i=0;i<arr.size();i++){
		int tmp=exc;
		exc=max(inc,exc);
		inc=tmp+arr[i];
	}
	return max(inc,exc);
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<maxSum(arr)<<"\n";
}