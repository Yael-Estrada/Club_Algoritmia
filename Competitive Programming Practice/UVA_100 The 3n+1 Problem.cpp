#include<bits/stdc++.h>
using namespace std;

//	UVA-100 "The 3n+1 Problem"	Yael Estrada	

int main(){
	int a,b;
	while(cin>>a>>b){
	int mx=-1e9;
	if(a<b){
		for(int i=a;i<=b;i++){
			int n=i;
			int s=1;
			while(n!=1){
				if(n%2==0){
					n>>=1;
					s++;
				}
				else{
					n=3*n+1;
					n>>=1;
					s+=2;
				}
			}
			mx=max(s,mx);
		}
	}
	else{
		for(int i=b;i<=a;i++){
			int n=i;
			int s=1;
			while(n!=1){
				if(n%2==0){
					n>>=1;
					s++;
				}
				else{
					n=3*n+1;
					n>>=1;
					s+=2;
				}
			}
			mx=max(s,mx);
		}
	}
	cout<<a<<" "<<b<<" "<<mx<<"\n";
	}

}