#include<bits/stdc++.h>
using namespace std;

typedef pair<string,string> par;

set<par> visited;

bool Buscar(string act,vector<string> &ruta,vector<par> &destinos){
	if(ruta.size()==destinos.size()+1){
		return true;
	}

	for(int i=0;i<destinos.size();i++){
		if(destinos[i].first==act&&!visited.count(destinos[i])){
			if(ruta.size()==0) ruta.push_back(act);
			ruta.push_back(destinos[i].second);
			visited.insert(destinos[i]);
			if(Buscar(destinos[i].second,ruta,destinos)){
				return true;
			}
			else{
				ruta.pop_back();
				visited.erase(destinos[i]);
			}
		}
	}
	return false;
}

vector<string> booking(string ini,vector<par> &destinos){
	vector<string> ruta;
	visited.clear();
	if(Buscar(ini,ruta,destinos))
		return ruta;
	else
		return vector<string>();
}

int main(){
	int n;
	cin>>n;
	par p;
	vector<par> destinos;
	for(int i=0;i<n;i++){
		cin>>p.first>>p.second;
		destinos.push_back(p);
	}
	string start;
	cin>>start;
	vector<string> itinerario=booking(start,destinos);
	for(auto &c:itinerario){
		cout<<c<<" ";
	} 
	if(itinerario.size()==0) cout<<"No se cuele";
	cout<<"\n";
	return 0;
}