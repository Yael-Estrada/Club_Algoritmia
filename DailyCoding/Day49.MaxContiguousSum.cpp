#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &nums){
	int mx=0,acum=0;
	for(int i=0;i<nums.size();i++){
		acum=max(acum+nums[i],nums[i]);
		mx=max(mx,acum);
	}
	return mx;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<maxSum(nums)<<"\n";
	return 0;
}