#include<bits/stdc++.h>
using namespace std;

void medianas(vector<int> &ar){
	double median=0;
	priority_queue<double> maxheap;
	priority_queue<double,vector<double>,greater<double>> minheap;
	maxheap.push(ar[0]);
	median=ar[0];
	cout<<median<<"\n";
	for(int i=1;i<ar.size();i++){
		if(maxheap.size()>minheap.size()){
			if(ar[i]<median){
				int tmp=maxheap.top();
				maxheap.pop();
				minheap.push(tmp);
				maxheap.push(ar[i]);
			}
			else{
				minheap.push(ar[i]);
			}
			median=(maxheap.top()+minheap.top())/2.0;
		}
		else{
			if(maxheap.size()<minheap.size()){
				if(ar[i]>median){
					int tmp=minheap.top();
					minheap.pop();
					maxheap.push(tmp);
					minheap.push(ar[i]);
				}
				else{
					maxheap.push(ar[i]);
				}
				median=(maxheap.top()+minheap.top())/2.0;
			}
			else{
				if(ar[i]<median){
					maxheap.push(ar[i]);
					median=maxheap.top();
				}
				else{
					minheap.push(ar[i]);
					median=minheap.top();
				}
			}
		}

		cout<<median<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	medianas(arr);
	return 0;
}