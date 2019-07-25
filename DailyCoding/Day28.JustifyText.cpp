#include<bits/stdc++.h>
using namespace std;

vector<string> distribute(vector<string> &in,int k){
	vector<string> espacios;
	vector<string> res;
	string s="";
	int pointer=0;
	int faltan=k;
	int caben=0;
	for(int i=0;i<in.size();i++){
		if(in[i].size()<=faltan){
			caben++;
			faltan-=in[i].size();
			if(caben>1){
				espacios.push_back(" ");
				faltan--;
			}

		}
		else{
			int h=0;
			while(faltan>0){
				espacios[h]+=" ";
				faltan--;
				h=(h+1)%espacios.size();
			}
			int x=0;
			while(caben--){
				s+=in[pointer++];
				if(x<espacios.size())
					s+=espacios[x++];
			}
			faltan=k;
			res.push_back(s);
			s="";
			espacios.clear();
			caben=0;
			i--;
		}
	}
	if(espacios.size()==0) espacios.push_back(" ");
	int h=0;
	while(faltan>0){
		espacios[h]+=" ";
		faltan--;
		h=(h+1)%espacios.size();
	}
	int x=0;
	while(caben--){
		s+=in[pointer++];
		if(x<espacios.size())
			s+=espacios[x++];
	}
	res.push_back(s);

	return res;
}

int main(){
	int n;
	cin>>n;
	vector<string> cads(n);
	for(int i=0;i<n;i++){
		cin>>cads[i];
	}
	int k;
	cin>>k;
	vector<string> res=distribute(cads,k);
	for(auto &c: res){
		cout<<c<<"\n";
	}
}