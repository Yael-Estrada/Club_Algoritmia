#include <bits/stdc++.h>
using namespace std;


/*************		OmegaUp		"Subarreglos e Intervalos"	with Wavelet Tree	***********/
/************						Yael Estrada								**********/
struct WaveletTree
{
	long long int lo, hi;//lo: el minimo valor en nuestra subsecuencia y hi: el mayor valor.
	WaveletTree *left, *right;//Apuntadores a nuestros hijos izquierdo y derecho.
	vector<long long int> mapLeft;//Vector que contendra todos los mapLeft que necesitemos
	
	WaveletTree(vector<long long int>::iterator from, vector<long long int>::iterator to, long long int lo,long long int hi)/*:lo(x),hi(y)*/{
		this->lo=lo;
		this->hi=hi;
		if(from >= to) 
			return;
		//	Calculamos nuestro m, valor que ayudara a dividir la subsecuencia
		long long int m = (lo + hi) >> 1;
		//Esta funcion nos indica si el parametro x es menor o igual a nuestra m previamente calculada
		auto f = [m](int x){
			return x <= m;
		};

		//	Reservamos la cantidad(numero de elementos en el rango) necesaria para nuestro arreglo de mapLeft.
		mapLeft.reserve(to - from + 1);
		//	Como indexamos en 1, anadimos un cero para obviar el mapLeft[0]=0.
		mapLeft.push_back(0);
		

		for(auto it = from; it != to; ++it){

			auto leq = f(*it);//leq: Less than or equal

			mapLeft.push_back(mapLeft.back() + leq);
		}
		
		if(hi != lo){
			
			auto pivot = stable_partition(from, to, f);

			left = new WaveletTree(from, pivot, lo, m);

			right = new WaveletTree(pivot, to, m + 1, hi);
		}
	}
	
	int kth(int l, int r, int k){
		//	Si estamos en un rango que no es valido
		if(l > r) 
			return -1;
		//	Si llegamos a un nodo hoja entonces nuestro resultado es el valor en ese nodo
		if(lo == hi) 
			return lo;
		int lb = mapLeft[l - 1], rb = mapLeft[r];
		//	inLeft es la cantidad de elementos en el rango [l,r] que iran a la izquierda
		//	Esto se calcula mediante la resta: mapLeft[r] - mapLeft[l-1]
		int inLeft = rb - lb;
		//	Si nuestra cantidad de numeros en inLeft es mayor o igual a nuestra k, iremos a la izquierda
		//	y nuestros indices ahora seran mapLeft[l-1]+1 y mapLeft[r]
		if(k <= inLeft) 
			return left->kth(lb + 1, rb, k);
		else // Si es k es mayor a inLeft, iremos a la derecha. Hay que restar inLeft al k.
			return right->kth(l - lb, r - rb, k - inLeft);
	}

	
	long long int lessThanOrEqual(long long int l, long long int r,long long int x){
		//Caso 1
		if(l > r || x < lo) 
			return 0;
		//Caso 3
		if(hi <= x) 
			return r - l + 1;
		//Usamos el mapLeft de nuevo para obtener nuestros indices
		if(l==0){
			l++;
		}
		long long int lb = mapLeft[l - 1], rb = mapLeft[r];
		//Caso 2
		return left->lessThanOrEqual(lb + 1, rb, x) + right->lessThanOrEqual(l - lb, r - rb, x);
	}

	int GreaterThan(int izq, int der, int valor){
        if(valor < lo || izq > der)
            return (der - izq + 1);
        if(valor >= hi)
            return 0;
        int alaIzq, alaDer, seVanIzq;
        alaIzq = mapLeft[izq - 1];
        alaDer = mapLeft[der];
        seVanIzq = alaDer - alaIzq;
        return (left -> GreaterThan(alaIzq + 1, alaDer, valor) +
            right -> GreaterThan(izq - alaIzq, der - alaDer, valor));
    }

    int lessThan(int l,int r,int x){
    	if(l > r || x <= lo) 
			return 0;
		//Caso 3
		if(hi < x) 
			return r - l + 1;
		//Usamos el mapLeft de nuevo para obtener nuestros indices
		long long int lb = mapLeft[l - 1], rb = mapLeft[r];
		//Caso 2
		return left->lessThan(lb + 1, rb, x) + right->lessThan(l - lb, r - rb, x);
    }


    

};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n,m,q,lp,rp,ap,bp,l,r,a,b,last=0,tmp;
	cin>>n>>m>>q;
	long long int minimo=1e9,maximo=-1e9;
	vector<long long int> num(n);
	for (long long int i = 0; i < n; ++i){
		cin >> num[i];
		minimo=min(minimo,num[i]);
		maximo=max(maximo,num[i]);
	}
	WaveletTree w(num.begin(), num.end(),minimo,maximo);

	for(long long int x=0;x<q;x++){
		cin>>lp>>rp>>ap>>bp;
		l=(lp+last)%n+1;
		r=(rp+last)%n+1;
		a=(ap+last)%m+1;
		b=(bp+last)%m+1;
		if(l>r){
			tmp=l;
			l=r;
			r=tmp;
		}
		if(a>b){
			tmp=a;
			a=b;
			b=tmp;
		}
		last=w.lessThanOrEqual(l,r,b)-w.lessThan(l,r,a);
		cout<<last<<"\n";
	}
	
	return 0;
}