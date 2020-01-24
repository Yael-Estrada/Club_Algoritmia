#include<bits/stdc++.h>
using namespace std;

//	UVA-394	"Mapmaker"	Yael Estrada

struct arreglo{
public:
	string name;
	int base;
	int sizeofElems;
	int D;
	vector<int> lows,upps;
};
struct reference{
	string name;
	vector<int> indexes;
	arreglo a;
};

arreglo findArray(string name,vector<arreglo> &ar){
	for(int i=0;i<ar.size();i++){
		if(ar[i].name.compare(name)==0){
			return ar[i];
		}
	}
}

void procesar(reference &ref){
	string response=ref.a.name;
	arreglo a=ref.a;
	response+="[";
	for(int i=0;i<ref.indexes.size();i++){
		response+=to_string(ref.indexes[i]);
		if(i!=ref.indexes.size()-1) response+=", ";
	}
	response+="]";
	vector<int> Cs(a.D);
	Cs[a.D-1]=a.sizeofElems;
	for(int i=a.D-2;i>=0;i--){
		Cs[i]=Cs[i+1]*(a.upps[i+1]-a.lows[i+1]+1);
	}
	int co=a.base;
	for(int i=0;i<a.D;i++){
		co-=(Cs[i]*a.lows[i]);
	}
	int number=co;
	for(int i=0;i<a.D;i++){
		number+=(Cs[i]*ref.indexes[i]);
	}
	Cs.clear();
	cout<<response<<" = "<<number<<"\n";
}

int main(){
	int n,k;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	vector<arreglo> arreglos(n);
	for(int i=0;i<n;i++){
		cin>>arreglos[i].name;
		cin>>arreglos[i].base>>arreglos[i].sizeofElems>>arreglos[i].D;
		int a,b;
		for(int j=0;j<arreglos[i].D;j++){
			cin>>a>>b;
			arreglos[i].lows.push_back(a);
			arreglos[i].upps.push_back(b);
		}


	}
	string response="[";
	vector<reference> refs(k);
	int tmp;
	for(int i=0;i<k;i++){
		cin>>refs[i].name;
		arreglo a=findArray(refs[i].name,arreglos);
			refs[i].a=a;
			for(int j=0;j<a.D;j++){
				cin>>tmp;
				refs[i].indexes.push_back(tmp);
			}

	}

	for(int i=0;i<refs.size();i++){
		procesar(refs[i]);
	}
	

	return 0;
}