#include<bits/stdc++.h>
using namespace std;

/******* 	Codeforces 1037B "Reach Median" Greedy Algorithm 	*******/
/*******			Yael Estrada 				******/

int main(){
	int n,s;
	cin>>n>>s;
	long long int mid=n/2;
	vector<long long int> arr(n);
	for(long long int i=0;i<n;i++){
		cin>>arr[i];
	}
	int alreves=0;
	sort(arr.begin(),arr.end());
	long long int mins=0;
	if(s<arr[mid]){
		alreves=1;
	}
	mins=abs(s-arr[mid]);
	arr[mid]=s;
	if(alreves==0){
		for(long long int i=mid+1;i<arr.size();i++){
			if(arr[i]<s){
				mins+=s-arr[i];
				arr[i]=s;
			}
			else{
				break;
			}
		}
	}
	else{
		for(long long int i=mid-1;i>=0;i--){
			if(arr[i]>s){
				mins+=arr[i]-s;
				arr[i]=s;
			}
			else{
				break;
			}
		}
	}
	cout<<(long long int)mins<<endl;

return 0;
}
