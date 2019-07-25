#include<bits/stdc++.h>
using namespace std;
/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.

Solution.
Since they are giving us a map with only 26 posible options of decode a group of letters we need to know how many times we can
reduce the size of the string decoding the first one of two characters.
For example: if we have the string 12345, we separate or decode the first char and we have that the answer is 1+decode(2345),
but separating the first two chars we have that also the answer count that is 12+decode(345), so we made a function recursive
that take the first char and call to the function againt with a string of n-1 (n is the size of the string), but when the first
two chars are less or equal than 26 we can call the function recursively with a string of n-2, and then we add the both
answers, if the first two chars are greater than 26 we only take in count the decode function with a string of n-1 size.

Important to note that if the string starts with 0 at a base case we return 0, and with an empty string we return 1.

To optimize the answer because it is recursively we used a dp memory to keep the number of ways of decoding a substring with
size of i characters in the ith position of the mem array.
*/

int mem[1000];

int ways(string data){
	if(mem[data.size()]!=-1) return mem[data.size()];
	if(data.size()==0) return 1;
	if(data.size()==1){
		if(data[0]!='0') return 1;
		else return 0;
	}
	if(data.size()==2){
		int n=stoi(data);
		if(data[0]=='0') return 0;
		else{
			if(n<27&&n>10) return 2;
			else return 1;
		}
	}
	if(data[0]=='0') return 0;
	string cad="";
	cad+=data[0];
	cad+=data[1];
	int uno=ways(data.substr(1,data.size()-1)),dos;
	if(stoi(cad)<27){
		dos=ways(data.substr(2,data.size()-2));
	}
	else dos=0;
	mem[data.size()]=uno+dos;
	return uno+dos;
}

int main(){
	string data;
	cin>>data;
	for(int i=0;i<=data.size();i++) mem[i]=-1;
	cout<<ways(data)<<"\n";	
	return 0;
}