#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 pair<int,ListNode*> borrarNodo(ListNode* nodo,int n,int act){
    if(nodo->next==NULL){
        if(n==1)
            return make_pair(1,(ListNode*)NULL);
        else
            return make_pair(1,nodo);
    }
    else{
        pair<int,ListNode*> num=borrarNodo(nodo->next,n,1+act);
        if(1+num.first==n){
            nodo->val=num.second->val;
            nodo->next=num.second->next;
            return make_pair(1+num.first,nodo);
        }
        else{
            nodo->next=num.second;
            return make_pair(1+num.first,nodo);
        }
    }
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    pair<int,ListNode*> x=borrarNodo(head,n,0);
    return x.second;
}



int main(){
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head=removeNthFromEnd(head,2);
	while(head!=NULL){
		cout<<head->val<<"\n";
		head=head->next;
	}
}