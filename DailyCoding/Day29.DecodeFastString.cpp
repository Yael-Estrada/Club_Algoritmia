#include<bits/stdc++.h>
using namespace std;

string encoding(string cadena){
	string s="";
	int num=0;
	char c=0;
	for(int i=0;i<cadena.size();i++){
		if(c==0){
			c=cadena[i];
			num++;
		}
		else{
			if(cadena[i]==c){
				num++;
			}
			else{
				s+=to_string(num);
				s+=c;
				c=cadena[i];
				num=1;
			}
		}
	}
	s+=to_string(num);
	s+=c;
	return s;
}

string decoding(string s){
	int num=0;
	string cad="",temp="";
	char c=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			temp+=s[i];
		}
		else{
			c=s[i];
			if(temp=="") continue;
			num=stoi(temp);
			temp="";
			while(num--){
				cad+=c;
			}
		}
	}
	return cad;
}

int main(){
	string s;
	cin>>s;
	
	cout<<(s=encoding(s))<<"\n";
	cout<<decoding(s)<<"\n";
}