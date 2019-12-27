#include<bits/stdc++.h>
using namespace std;

//	UVA 661	(Ad Hoc) "Blowing Fuses"	Yael Estrada

int main(){
	int n,m,c;
	int seq=0;
	while(cin>>n>>m>>c&&n&&m&&c){
		seq++;
		vector<int> turned(n,0);
		vector<int> amperes(n);
		for(int i=0;i<n;i++){
			cin>>amperes[i];
		}
		int consumo=0;
		bool blown=false;
		int tmp,consmax=-1e9;
		for(int i=0;i<m;i++){
			cin>>tmp;
			turned[tmp-1]=1-turned[tmp-1];
			if(turned[tmp-1]==1){
				consumo+=amperes[tmp-1];
			}
			else{
				consumo-=amperes[tmp-1];
			}
			consmax=max(consmax,consumo);
			if(consumo>c) blown=true;
		}
		if(blown)
			cout<<"Sequence "<<seq<<"\nFuse was blown.\n\n";
		else
			cout<<"Sequence "<<seq<<"\nFuse was not blown.\nMaximal power consumption was "<<consmax<<" amperes.\n\n";

		turned.clear();
		amperes.clear();
	}
	return 0;
}