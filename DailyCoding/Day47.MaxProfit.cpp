#include<bits/stdc++.h> 
using namespace std;

int maxProfit(vector<int> &nums){
	int n=nums.size();
	if(n==0) return 0;
	int mn=nums[0];
	int mx=0;
	for(int i=1;i<n;i++){
		mx=max(mx,nums[i]-mn);
		mn=min(mn,nums[i]);
	}
	return mx;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	cout<<maxProfit(nums)<<"\n";
	return 0;
}