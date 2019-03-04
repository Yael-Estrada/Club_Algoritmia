#include<bits/stdc++.h>
using namespace std;

/********** HackerRank "The Coin Change problem"	DP Algorithm 		 ************/
/**********				Yael Estrada				 ***********/


int main(){
	int N,M;
	int a[1005];
	cin>>M>>N;
	int currentCoin;
	vector<long long int> combinaciones(M+1);
	for(int i=0;i<N;i++)
		cin>>a[i];
	combinaciones[0]=1;
	for(int i=0;i<N;i++){
		currentCoin=a[i];
		for(int j=1;j<=M;j++){
			while(j<currentCoin&&j<=M){
				j++;
			}
			if(j<M+1)
				combinaciones[j]+=combinaciones[j-currentCoin];
		}
	}
	cout<<combinaciones[M]<<endl;
	return 0;
}
