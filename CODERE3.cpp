#include<bits/stdc++.h>
using namespace std;

/************ 	SPOJ	CODERE3-"CODER EXPRESS 3!!"	DP Algorithm		*************/
/************						Yael Estrada						************/

int LISD(vector<int> arr,int n){
vector<int> l(n,0),r(n,0);
int maximo=-1e9;
l[0]=1;
r[n-1]=1;
for(int i=1;i<n;i++){
	for(int j=0;j<i;j++){
		if(arr[j]<arr[i]&&l[i]<l[j]+1){
			l[i]=l[j]+1;
		}	
		else{
			l[i]=max(1,l[i]);
		}		
	}
}
for(int i=n-2;i>=0;i--){
	for(int j=n-1;j>i;j--){
		if(arr[j]<arr[i]&&r[i]<r[j]+1){
			r[i]=r[j]+1;
		}
		else{
			r[i]=max(1,r[i]);
		}
	}
}
int indmx;
for(int i=0;i<n;i++){
	if(maximo<l[i]+r[i]){
		maximo=l[i]+r[i];
		indmx=i;
	}
}
int cnt=0;
for(int i=0;i<indmx;i++){
	if(cnt+1==l[i]){
		cnt++;
	}
}
cnt++;
int cnt2=0;
cnt2=r[indmx];
for(int j=indmx;j<n;j++){
	if(r[j]==cnt2-1){
		cnt++;
		cnt2--;
	}
}

return cnt;

}

int main(){
	int N;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests;
	cin>>tests;
	while(tests--){
		cin>>N;
		vector<int> arr(N);
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}

		
		cout<<LISD(arr,N)<<"\n";

	}
	return 0;
}