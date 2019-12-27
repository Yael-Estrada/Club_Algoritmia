/*@brief UVA 10141 (Ad Hoc) Request For proposal 	Yael Estrada
*/
#include<bits/stdc++.h>
using namespace std;

struct proposal{
	string Name;
	float price;
	int mets;
};

float compliance(proposal p,int req){
	return (float)p.mets/(float)req;
}
bool isBetter(proposal p,proposal b,int r){
	if(compliance(p,r)>compliance(b,r)) return true;
	if(compliance(p,r)==compliance(b,r)){
		if(p.price<b.price){
			return true;
		}
	}
	return false;
}

proposal RPF(vector<proposal> &prop,int req){
	proposal better;
	better.mets=-1;
	for(int i=0;i<prop.size();i++){
		if(prop[i].mets==req){
			if(better.mets==-1) better=prop[i];
			else{
				if(better.price>prop[i].price){
					better=prop[i];
				}
			}
		}
	}
	if(better.mets==-1){
		better=prop[0];
		for(int i=1;i<prop.size();i++){
			if(isBetter(prop[i],better,req)){
				better=prop[i];
			}
		}
	}
	return better;
}

int main(){
	int requests,proposals;
	int num=0;
	string s;
	while(cin>>requests>>proposals&&requests&&proposals){
		if(num!=0) cout<<"\n";
		vector<string> req(requests);
		cin.ignore();
		for(int i=0;i<requests;i++){
			getline(cin,req[i]);
		}
		vector<proposal> prop(proposals);
		for(int i=0;i<proposals;i++){
			getline(cin,prop[i].Name);
			cin>>prop[i].price;
			cin>>prop[i].mets;
			cin.ignore();
			for(int j=0;j<prop[i].mets;j++){
				getline(cin,s);
			}
		}
		cout<<"RFP #"<<++num<<"\n"<<RPF(prop,requests).Name<<"\n";
	}
}