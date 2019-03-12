#include<bits/stdc++.h>
using namespace std;

/************ 	Codeforces 1097B	"Petr and a Combination Lock"	DP algorithm 	**************/
/***********						Yael Estrada							*************/

int dp[16][361];
int cambios[16];


string Velocimetro(int n){
	dp[0][cambios[0]]=1;
	dp[0][360-cambios[0]]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<361;j++){
			if(dp[i-1][j]==1){
				if(j+cambios[i]>360){
					dp[i][j+cambios[i]-360]=1;
				}
				else{
				 	dp[i][j+cambios[i]]=1;
				}
				if(j-cambios[i]<0){
					dp[i][360+j-cambios[i]]=1;
				}
				else{
					dp[i][j-cambios[i]]=1;
				}
			}
		}
	}

	if(dp[n-1][0]==1||dp[n-1][360]==1)
		return "YES";
	return "NO";

}

int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
	cin>>cambios[i];
}
for(int j=0;j<n;j++){
for(int i=0;i<361;i++){
	dp[j][i]=0;
}}

cout<<Velocimetro(n)<<"\n";	

}