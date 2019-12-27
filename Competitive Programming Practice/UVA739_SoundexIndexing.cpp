#include<bits/stdc++.h>
using namespace std;

//	UVA 739	(Ad-Hoc)	"Soundex Indexing"	Yael Estrada

int main(){
	map<char,int> code;
	code.insert(make_pair('B',1));
	code.insert(make_pair('P',1));
	code.insert(make_pair('F',1));
	code.insert(make_pair('V',1));
	code.insert(make_pair('C',2));
	code.insert(make_pair('S',2));
	code.insert(make_pair('K',2));
	code.insert(make_pair('G',2));
	code.insert(make_pair('J',2));
	code.insert(make_pair('Q',2));
	code.insert(make_pair('X',2));
	code.insert(make_pair('Z',2));
	code.insert(make_pair('D',3));
	code.insert(make_pair('T',3));
	code.insert(make_pair('L',4));
	code.insert(make_pair('M',5));
	code.insert(make_pair('N',5));
	code.insert(make_pair('R',6));
	string name;
	vector<string> codigos;
	vector<string> names;
	while(cin>>name){
		string codex;
		names.push_back(name);
		codex+=name[0];
		for(int i=1;i<name.size();i++){
			if(name[i]=='E'||name[i]=='A'||name[i]=='I'||name[i]=='O'||name[i]=='U'||name[i]=='Y'||name[i]=='W'||name[i]=='H') continue;

			int valor=code[name[i]];
			if(valor!=codex[codex.size()-1]&&valor!=code[name[i-1]]){
				codex+=to_string(valor);
			}
			if(codex.size()==4){
				break;
			}
		}
		while(codex.size()!=4){
			codex+='0';
		}
		codigos.push_back(codex);
	}

	string col10="         ";
	string col20="                   ";
	cout<<col10<<"NAME";
	for(int i=14;i<35;i++){
		cout<<" ";
	}
	cout<<"SOUNDEX CODE\n";
	for(int i=0;i<codigos.size();i++){
		cout<<col10;
		cout<<names[i];
		for(int j=10+names[i].size();j<35;j++){
			cout<<" ";
		}
		cout<<codigos[i]<<"\n";
	}
	cout<<col20<<"END OF OUTPUT\n";

}