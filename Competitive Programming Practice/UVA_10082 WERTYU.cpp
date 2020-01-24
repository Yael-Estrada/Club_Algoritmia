/* @brief UVA 10082 (Ad Hoc) WERTYU		Yael Estrada
*/
#include<bits/stdc++.h>
using namespace std;

unordered_map<char,char> mapa;

void llenar_mapa(){
	mapa.insert(make_pair('1','`'));
	mapa.insert(make_pair('2','1'));
	mapa.insert(make_pair('3','2'));
	mapa.insert(make_pair('4','3'));
	mapa.insert(make_pair('5','4'));
	mapa.insert(make_pair('6','5'));
	mapa.insert(make_pair('7','6'));
	mapa.insert(make_pair('8','7'));
	mapa.insert(make_pair('9','8'));
	mapa.insert(make_pair('0','9'));
	mapa.insert(make_pair('-','0'));
	mapa.insert(make_pair('=','-'));
	mapa.insert(make_pair('W','Q'));
	mapa.insert(make_pair('E','W'));
	mapa.insert(make_pair('R','E'));
	mapa.insert(make_pair('T','R'));
	mapa.insert(make_pair('Y','T'));
	mapa.insert(make_pair('U','Y'));
	mapa.insert(make_pair('I','U'));
	mapa.insert(make_pair('O','I'));
	mapa.insert(make_pair('P','O'));
	mapa.insert(make_pair('[','P'));
	mapa.insert(make_pair(']','['));
	mapa.insert(make_pair('\\',']'));
	mapa.insert(make_pair('S','A'));
	mapa.insert(make_pair('D','S'));
	mapa.insert(make_pair('F','D'));
	mapa.insert(make_pair('G','F'));
	mapa.insert(make_pair('H','G'));
	mapa.insert(make_pair('J','H'));
	mapa.insert(make_pair('K','J'));
	mapa.insert(make_pair('L','K'));
	mapa.insert(make_pair(';','L'));
	mapa.insert(make_pair('\'',';'));
	mapa.insert(make_pair('X','Z'));
	mapa.insert(make_pair('C','X'));
	mapa.insert(make_pair('V','C'));
	mapa.insert(make_pair('B','V'));
	mapa.insert(make_pair('N','B'));
	mapa.insert(make_pair('M','N'));
	mapa.insert(make_pair(',','M'));
	mapa.insert(make_pair('.',','));
	mapa.insert(make_pair('/','.'));

}
string WERTYU(string cad){
	string res="";
	for(int i=0;i<cad.size();i++){
		if(mapa.count(cad[i])!=0){
			res+=mapa[cad[i]];
		}
		else{
			res+=cad[i];
		}
	}
	return res;
}
int main(){
	string line;
	llenar_mapa();
	while(getline(cin,line)&&line.size()!=0){
		cout<<WERTYU(line)<<"\n";
	}
	return 0;
}