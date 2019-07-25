#include<bits/stdc++.h>
using namespace std;

struct LRU{
	int n;
	deque<int> cola;
	map<int,int> hash;

	LRU(int tam): n(tam){}

	void set(int key,int value){
		if(cola.size()==n){
			hash.erase(cola.front());
			cola.pop_front();
		}
		hash.insert(make_pair(key,value));
		cola.push_back(key);
	}

	int get(int key){
		if(hash.count(key)==0) return -1;
		if(key==cola.front()){
			cola.push_back(cola.front());
			cola.pop_front();
		}
		return hash[key];
	}
};

int main(){
	LRU* l=new LRU(3);
	l->set(1,5);
	l->set(2,7);
	l->set(3,6);

	cout<<l->get(3)<<"\n";
	cout<<l->get(1)<<"\n";
	cout<<l->get(4)<<"\n";

	l->set(4,12);

	cout<<l->get(2)<<"\n";
	cout<<l->get(4)<<"\n";

}