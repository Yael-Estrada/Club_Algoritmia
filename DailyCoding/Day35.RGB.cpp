#include<bits/stdc++.h>
using namespace std;

void swapear(string &cad){
	int rs=0,bs=0,gs=0;
	for(int i=0;i<cad.size();i++){
		switch(cad[i]){
			case 'R': rs++; break;
			case 'G': gs++; break;
			case 'B': bs++; break;
		}
	}
	int apR=0,apG=rs,apB=rs+gs;
	int i=0;
	while(apR<rs){
		if(cad[i]=='R'){
			int tmp=cad[apR];
			cad[apR]=cad[i];
			cad[i]=tmp;
			apR++;
		}
		i++;
	}
	i=0;
	while(apG<rs+gs){
		if(cad[i]=='G'){
			int tmp=cad[apG];
			cad[apG]=cad[i];
			cad[i]=tmp;
			apG++;
		}
		i++;
	}
	i=0;
	while(apB<rs+gs+bs){
		if(cad[i]=='B'){
			int tmp=cad[apB];
			cad[apB]=cad[i];
			cad[i]=tmp;
			apB++;
		}
		i++;
	}
	
}

int main(){
	string s;
	cin>>s;
	swapear(s);
	cout<<s<<"\n";
	return 0;
}