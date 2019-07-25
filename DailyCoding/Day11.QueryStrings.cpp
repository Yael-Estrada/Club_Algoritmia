#include <bits/stdc++.h>
using namespace std;

/*
This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Solution.
This problem is easily solved with the Trie data structure that implements a tree where each node is a letter of a word, 
words with the same preffix are in the same path and when they reach different letters the previous node adds a new child node
with the letter that diffiers from the already inserted.

So, in order to do de search we iterate over the Trie until we finish the preffix that we are looking for, next we call a
recursive function that takes every distinct child and appends its suffix to the search preffix and insert it into a vector
this is for every subtree of the Trie. 

*/

struct Nodo{
	unordered_map <char, Nodo*> hijos;
	int fin, prefix;
	Nodo(): fin(0), prefix(0){}	
};

struct Trie{
	Nodo *raiz;

	Trie() : raiz( new Nodo() ){}

	void insert( string s ){
		Nodo* act= raiz;
		for (auto &c : s){
			if(!(act->hijos).count(c))
				act->hijos[c] = new Nodo();
			act = act->hijos[c];
			act->prefix++;
		}
		act->fin++;
	}

	int query(string s){
		Nodo* act = raiz;
		for( auto &c : s){
			if( !(act->hijos.count(c)) )
				return 0;
			act = act->hijos[c];
		}
		return act->fin;
	}

	void insertString(vector<string> &cads,string pref,Nodo* c){
		if(c->hijos.size()==0){
			cads.push_back(pref);
		}
		for(char a='a';a<='z';a++){
			if(c->hijos.count(a)){
				insertString(cads,pref+a,c->hijos[a]);
			}
		}
	}

	vector<string> buscar(string d){
		Nodo* act=raiz;
		vector<string> cads;
		string cad="";
		for(auto &c : d){
			if(!act->hijos.count(c)){
				return cads;
			}
			act=act->hijos[c];
		}
		insertString(cads,d,act);
		return cads;
	}
};

int main(){
	string pref;
	cin>>pref;
	int n;
	cin>>n;
	Trie trie;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		trie.insert(t);
	}
	vector<string> cads=trie.buscar(pref);
	for(string s:cads){
		cout<<s<<"\n";
	}
	


}