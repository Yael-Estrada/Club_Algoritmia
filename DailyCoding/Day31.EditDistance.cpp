#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	map<char,int> bolsa;
	for(int i=0;i<a.size();i++){
		if(!bolsa.count(a[i])) bolsa.insert(make_pair(a[i],1));
		else bolsa[a[i]]++;
	}
	int num=0;
	for(int i=0;i<b.size();i++){
		if(!bolsa.count(b[i])){
			num++;
		}
		else{
			bolsa[b[i]]--;
			if(bolsa[b[i]]==0)
				bolsa.erase(b[i]);
		}
	}
	cout<<num<<"\n";
}