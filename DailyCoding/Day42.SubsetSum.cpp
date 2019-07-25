#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int act,int k,vector<int> &nums,vector<int> &ans){
	if(k==0){
		return true;
	}
	if(k<0) return false;
	if(act>=nums.size()) return false;
	ans.push_back(nums[act]);
	bool b=subsetSum(act+1,k-nums[act],nums,ans);
	if(b) return b;
	ans.pop_back();
	b=subsetSum(act+1,k,nums,ans);
	if(b) return b;
	else
		return false;
}

int main(){
	int n,k;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	cin>>k;

	vector<int> ans;
	bool b=subsetSum(0,k,nums,ans);
	for(auto &c: ans){
		cout<<c<<" ";
	} 
	if(ans.size()==0||!b) cout<<"No se cuele";
	cout<<endl;
}