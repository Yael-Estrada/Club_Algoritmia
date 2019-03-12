#include<bits/stdc++.h>
using namespace std;

/************** 	Codeforces	320A	"Magic Numbers"		Greedy Algorithm 	************/
/*************					Yael Estrada									***********/

int main(){
	string magic;
	cin>>magic;
	vector<string> mn(3);
	mn[0]="1";
	mn[1]="14";
	mn[2]="144";
	string cad="";
	string tmp;
	int ap=0;
	while(cad.size()<magic.size()){
		if(magic.substr(ap,mn[2].size())==mn[2]){
			cad+=mn[2];
			ap+=mn[2].size();
		}
		else{
			if(magic.substr(ap,mn[1].size())==mn[1]){
				cad+=mn[1];
				ap+=mn[1].size();
			}
			else{
				if(magic.substr(ap,mn[0].size())==mn[0]){
					cad+=mn[0];
					ap+=mn[0].size();
				}
				else{
					cout<<"NO"<<"\n";
					break;
				}
			}
		}
	}
	if(cad==magic){
		cout<<"YES"<<"\n";
	}

return 0;
}