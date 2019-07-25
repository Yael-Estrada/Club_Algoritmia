#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. 
If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return
 ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either 
['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

Solution. 
Its a simple simulation problem
Its enough with create an aux string and every time we found a string that is contained on our diccionarie then we insert
it in the answer vector, it visit each character only once so it has a O(n) time complexity and it has a O(n) space
complexity because of the unordered_set.
*/

vector<string> reconstruir(unordered_set<string> &dic,string cad){
	string tmp="";
	vector<string> res;
	for(int i=0;i<cad.size();i++){
		tmp+=cad[i];
		if(dic.count(tmp)!=0){
			res.push_back(tmp);
			tmp="";
		}	
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	unordered_set<string> diccionario;
	string tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		diccionario.insert(tmp);
	}
	string cad;
	cin>>cad;
	vector<string> built=reconstruir(diccionario,cad);
	if(built.size()==0)
		cout<<"No se pudo reconstruir\n";
	for(int i=0;i<built.size();i++)
		cout<<built[i]<<"\n";
	return 0;
}