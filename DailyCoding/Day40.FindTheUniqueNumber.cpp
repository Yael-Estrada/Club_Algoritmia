#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &nums){
	int ones=0,twos=0,common=0;
	for(int i=0;i<nums.size();i++){
		twos=twos|(ones&nums[i]);
		ones=ones^nums[i];
		common=~(ones&twos);
		ones&=common;
		twos&=common;
	}
	return ones;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<find(nums)<<"\n";
}