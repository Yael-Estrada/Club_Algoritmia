#include<bits/stdc++.h>
using namespace std;

/**************		Codeforces	1081A-"Definite Game"		*************/
/*************				Yael Estrada					************/


int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<n<<"\n";
		return 0;
	}
	if(n%(n-1)==0){
		cout<<n<<"\n";
	}
	else{
		n-=n-1;
		cout<<n<<"\n";
	}

	return 0;
}