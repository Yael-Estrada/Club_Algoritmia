#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".


Solution.
I used a fast solution but huge in memory, i declared a map and a queue, the map count the times that a char c is repeated
and the queue is for the unique chars.
I made a linear iteration and every time i found a distinct char of those which i have inserted in the map, then i pop the
queue and erase the first element i have inserted of those that i had in the map, then i update the size of my string of k 
unique characters.

For a better solution, use a window that only focuses on the chars that we are looking for, with a variable called current 
start, move it until the unique chars that will be in the window be equal to K.
*/

int lds(string cad,int k){
	queue<char> cola;
	map<char,int> veces;
	veces.clear();
	int size=0,maxsize=0;
	for(int i=0;i<cad.size();i++){
		if(veces.size()<k){
			if(!veces.count(cad[i])){
				veces.insert(make_pair(cad[i],1));
				cola.push(cad[i]);
			}
			else{
				veces[cad[i]]++;
			}
			size++;

		}
		else if(veces.size()==k){
			if(veces.count(cad[i])){
				veces[cad[i]]++;
				size++;
			}
			else{
				char c=cola.front();
				cola.pop();
				int v=veces[c];
				size-=v;
				veces.erase(c);
				i--;
			}
		}
		if(size>maxsize) maxsize=size;
	}
	return maxsize;
}


int main(){
	string cadena;
	cin>>cadena;
	int k;
	cin>>k;
	cout<<lds(cadena,k)<<"\n";
	return 0;
}