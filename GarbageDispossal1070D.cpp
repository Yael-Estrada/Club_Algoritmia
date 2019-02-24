#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

/*********		Codeforces 1070D "Garbage Dispossal" Greedy Algorithm	 *********/
/*********			Yael Estrada		  			  *******/


int main(){
	int n,k,res=0,paotrodia=0;
	cin>>n>>k;
	vector<lli> basura(n);
	vector<lli> bolsas(n);
	for(lli i=0;i<n;i++){
		cin>>basura[i];
		basura[i]+=res;
		bolsas[i]=basura[i]/k;
		res=basura[i]%k;
		if(bolsas[i]==0&&paotrodia==1){
			bolsas[i]++;
			res=0;
		}
		if(res!=0){
			paotrodia=1;
		}
		else{
			paotrodia=0;
		}
	}
	if(res>0){
		bolsas[n-1]++;
	}
	lli sum=0;
	for(lli i=0;i<bolsas.size();i++){
		sum+=bolsas[i];
	}
	cout<<sum<<endl;

	return 0;
}
