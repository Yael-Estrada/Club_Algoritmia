#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, 
it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

Solution.
We create a structure called xorNode with a value and a pointer to next node (it contains the xor operation of the previous
pointer and the next pointer).

To add an element to the list, we need to keep the previous node that we have already visited, we search until the operation 
of the previous node visited and the next pointer be equal to zero, here is when we reach the end of the list, 
only we create a new node and append it with its respective operation

To traverse its the same idea, only we change the condition to if we reach the index that we were looking for, or if we reach
the last node of the list (the operation of the previous node visited and the next pointer equals to zero), and we print the
value of the node that we are visiting.

*/

struct xorNode{
	int val;
	xorNode* next;
	xorNode(int v): val(v),next(0){}
};

void add(xorNode* nodo,int val){
	if(nodo==NULL){
		nodo=new xorNode(val);
	}
	else{
		if(nodo->next==0){
			xorNode* nuevo=new xorNode(val);
			nodo->next=(xorNode*)((int)nodo->next^(int)nuevo);
			nuevo->next=nodo;
		}
		else{
			xorNode* prev=0;
			xorNode* aux=nodo;
			xorNode* aux2;
			do{
				aux2=aux;
				aux=(xorNode*)((int)prev^(int)aux->next);
				prev=aux2;
			}while(((int)prev^(int)aux->next)!=0);
			xorNode* nuevo=new xorNode(val);
			aux->next=(xorNode*)((int)nuevo^(int)aux->next);
			nuevo->next=aux;
		}
	}
}

void traverse(xorNode* nodo,int indice){
	if(indice==0) return;
	else{
		int ind=0;
		xorNode* prev=0;
		xorNode* aux=nodo;
		xorNode* aux2;
		while(ind!=indice){
			cout<<aux->val<<" ";
			aux2=aux;
			aux=(xorNode*)((int)prev^(int)aux->next);
			prev=aux2;
			ind++;
			if(((int)prev^(int)aux->next)==0){ break;}
		}
	}
	cout<<"\n";
}

int main(){
	xorNode* lista=new xorNode(-1);
	for(int i=0;i<5;i++){
		add(lista,i);
	}
	traverse(lista,5);
	return 0;
}