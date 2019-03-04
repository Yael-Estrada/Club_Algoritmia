#include<bits/stdc++.h>
using namespace std;

/************* 	OmegaUp	"Concierto del Dr. Lira"	DP algorithm 			**********/
/*************			Yael Estrada						*********/

int mem[55][10005];

long long int MaximoPosible(vector<long long int> cambios,int maxi){
	long long int n=cambios.size();
	long long int sube=0,baja=0;
	for(long long int i=1;i<=n;i++){
		for(long long int j=0;j<=maxi;j++){
			if(mem[i-1][j]!=-1){
				sube=j+cambios[i-1];
				if(sube<=maxi){
					mem[i][sube]=1;
				}
				baja=j-cambios[i-1];
				if(baja>=0){
					mem[i][baja]=1;
				}
			}
		}
	}

	int mx=-1;
	for(long long int i=0;i<=maxi;i++){
		if(mem[n][i]!=-1){
			mx=i;
		}
	}
	return mx;
}


int main(){
	int n;
	cin>>n;
	vector<long long int> cambios(n);
	for(long long int i=0;i<n;i++){
		cin>>cambios[i];
	}
	long long int ini,maxi;
	cin>>ini>>maxi;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=maxi;j++){
			mem[i][j]=-1;
		}
	}

	mem[0][ini]=1;
	cout<<MaximoPosible(cambios,maxi)<<"\n";

	return 0;
}
