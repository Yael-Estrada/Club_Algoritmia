#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. 
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

Solution.
First of all, we segregate the numbers into postitive and negative/0, so the array will be divided in two sides, we left
the positive numbers in right place of the array.
We store the position of where the positive numbers starts, in other words we store how many negative/0 numbers we have
Next, we call to a function with only the positive part of the array, and we mark the index at the values of the array making
that value a negative value, so the first n integers will be negative (n is the positive array size) and we look for the first
positive integer in the array, this means that that number of the index isnt in the array, we return i+1 because is indexed in 0.
if we have all integers negative, we return the array size plus one because the missing number is over the size of the array.

*/

int segregate(int nums[],int size){
	int ind=0;
	for(int i=0;i<size;i++){
		if(nums[i]<=0){
			int tmp=nums[i];
			nums[i]=nums[ind];
			nums[ind]=tmp;
			ind++;
		}
	}
	return ind;
}

int lowest(int nums[],int size){
	for(int i=0;i<size;i++){
		if(abs(nums[i]) - 1 < size && nums[ abs(nums[i]) - 1] > 0)  
        nums[ abs(nums[i]) - 1] *=-1;  
		
	}
	for(int i=0;i<size;i++){
		if(nums[i]>0){ 
			return i+1;
		}
	}
	return size+1;
}

int lowestMissing(int nums[],int size){
	int ind=segregate(nums,size);

	return lowest(nums+ind,size-ind);
}

int main(){
	int n;
	cin>>n;
	int dat[n];
	for(int i=0;i<n;i++){
		cin>>dat[i];
	}
	cout<<lowestMissing(dat,n)<<"\n";
	return 0;
}