#include<bits/stdc++.h>
using namespace std;

struct cola{
	stack<int> pila;
	stack<int> aux;

	int top(){
		if(pila.empty()&&aux.empty()) return -1;
		if(aux.empty()){
			while(!pila.empty()){
				aux.push(pila.top());
				pila.pop();
			}
		}
		return aux.top();
	}

	void pop(){
		if(aux.empty()){
			while(!pila.empty()){
				aux.push(pila.top());
				pila.pop();
			}
		}
		aux.pop();
	}

	void push(int x){
		pila.push(x);
	}	
};

int main(){
	cola c;
	c.push(1);
	c.push(3);
	c.push(8);
	c.push(5);

	cout<<c.top()<<"\n";
	c.pop();
	cout<<c.top()<<"\n";
}