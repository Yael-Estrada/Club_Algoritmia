/*********	Codeforces	189A-"Cut Ribbon" 	DP algorithm 	***********/
/*********		    Yael Estrada				**********/

#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
vector<int> res;

int r(int n){
	if(n==0) return 0;
	if(n<0) return -1e9;
	if(res[n]!=-1) return res[n];
	int ret=max(r(n-a),max(r(n-b),r(n-c)))+1;
	res[n]=ret;
	return ret;
}

int main(){
	cin>>n;
	cin>>a>>b>>c;
	for(int i=0;i<n+1;i++){
		res.push_back(-1);
	}
	int respuesta=r(n);
	cout<<respuesta<<endl;
}
