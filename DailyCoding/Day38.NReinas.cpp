#include<bits/stdc++.h>
using namespace std;

bool buscar(int act,int col,int n,vector<int> &ans){
	for(int i=col-1;i>=0;i--){
		if(act==ans[i]||(ans[i]-i)==(act-col)||(ans[i]+i)==(act+col))
			return false;
	}
	ans[col]=act;
	if(col==n-1) return true;
	for(int i=0;i<n;i++){
		if(buscar(i,col+1,n,ans))
			return true;
	}
	return false;
}

vector<int> NReinas(int n){
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		if(buscar(i,0,n,ans))
			return ans;
	}
	return vector<int>();
}

int main(){
	int n;
	cin>>n;
	vector<int> ans=NReinas(n);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	if(ans.size()==0) cout<<"No se puele";
	cout<<endl;
}