#include<bits/stdc++.h>
using namespace std;

void Powerear(vector<int> &nums,vector<vector<int>> &ps){
	for(int i=0;i<nums.size();i++){
		for(int j=0;j<ps.size();j++){
			vector<int> arr=ps[j];
			arr.push_back(nums[i]);
			ps.push_back(arr);
			if(j==(1<<i)-1)
				break;
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	vector<vector<int>> powerset;
	powerset.push_back(vector<int>());
	Powerear(ar,powerset);
	cout<<powerset.size()<<"\n";
}