#include<bits/stdc++.h>
using namespace std;

//	UVA-272	"TEX Quotes"	Yael Estrada

int main(){
	string s;
	int abre=0;
	while(getline(cin,s)){
		string nueva;
		for(int i=0;i<s.size();i++){
			if(s[i]=='"'){
				if(abre==0){
					nueva+="``";
				}
				if(abre==1){
					nueva+="''";
				}
				abre=1-abre;
			}
			else{
				nueva+=s[i];
			}
		}
		cout<<nueva<<"\n";
	}
	return 0;
}