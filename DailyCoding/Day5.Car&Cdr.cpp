#include<bits/stdc++.h>
using namespace std;

class par{
	public:
		int first;
		int second;

	par(int a,int b): first(a),second(b){}

};

par cons(int a,int b){
	return par(a,b);
}

int car(par x){
	return x.first;
}

int cdr(par x){
	return x.second;
}

int main(){
	par x=cons(1,2);
	cout<<car(x)<<"\n";
	cout<<cdr(x)<<"\n";
}