#include<bits/stdc++.h>
using namespace std;

int k=0;

void Merge(vector<int> &a,int lo,int hi,int mid){
	if(hi==lo) return;
	vector<int> arr(hi-lo+1);
	int i=lo,j=mid+1;
	int m=0;
	while(i<=mid&&j<=hi){
		if(a[i]<=a[j]){
			arr[m++]=a[i++];
		}
		else{
			k+=(mid-i+1);
			arr[m++]=a[j++];
		}
	}
	while(i<=mid){
		arr[m++]=a[i++];
	}
	while(j<=hi){
		arr[m++]=a[j++];
	}
	for(int l=0;l<m;l++){
		a[lo+l]=arr[l];
	}
}

void MergeSort(vector<int> &a,int lo,int hi){
	if(lo<hi){
		int mid=(hi+lo)>>1;
		MergeSort(a,lo,mid);
		MergeSort(a,mid+1,hi);
		Merge(a,lo,hi,mid);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	MergeSort(arr,0,arr.size()-1);
	cout<<k<<"\n";
	for(auto &c: arr){
		cout<<c<<" ";
	} cout<<"\n";
	return 0;
}