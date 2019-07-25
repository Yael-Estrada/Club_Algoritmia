#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.
Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.


Solution.
Count the nodes of both lists and walk down the bigger list until the number of nodes to visit are the same, then traverse
both lists until you find the same node, then return that node.

*/

struct Lista{
	int val;
	Lista *next;
	Lista(int x):val(x),next(NULL){}

	void Insert(Lista* l){
		Lista* aux=this;
		while(aux->next!=NULL){
			aux=aux->next;
		}
		aux->next=l;
	}
};



Lista* Intersection(Lista* l1,Lista* l2){
	Lista* aux1=l1,*aux2=l2;
	int c1=0,c2=0,d;
	while(aux1!=NULL){
		c1++;
		aux1=aux1->next;
	}
	aux1=l1;
	while(aux2!=NULL){
		c2++;
		aux2=aux2->next;
	}
	aux2=l2;
	d=abs(c1-c2);
	if(c1>c2){
		while(c1!=c2){
			c1--;
			aux1=aux1->next;
		}
		while(aux1->val!=aux2->val){
			aux1=aux1->next;
			aux2=aux2->next;
		}
		return aux1;
	}
	else{
		while(c1!=c2){
			c2--;
			aux2=aux2->next;
		}
		while(aux1->val!=aux2->val){
			aux1=aux1->next;
			aux2=aux2->next;
		}
		return aux2;
	}

}

int main(){
	int N,M,tmp;
	cin>>N;
	Lista *l1=NULL;
	Lista *l2=NULL;
	for(int i=0;i<N;i++){
		cin>>tmp;
		if(l1==NULL) l1=new Lista(tmp);
		else l1->Insert(new Lista(tmp));
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		if(l2==NULL) l2=new Lista(tmp);
		else l2->Insert(new Lista(tmp));
	}
	cout<<Intersection(l1,l2)->val<<"\n";
}