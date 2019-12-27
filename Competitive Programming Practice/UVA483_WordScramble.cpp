#include<bits/stdc++.h>
using namespace std;

//	UVA-483	"Word Scramble"	Yael Estrada

void reverse(string &str){
	int j = str.size() - 1;
    char temp;
    for (int i = 0; i < j; i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main(){
	string line="";
	string total="";
	char c;
	while(cin.get(c)){
		line+=c;
		if(c==0||c==10||cin.eof()){
			string tmp="";
			int ind=0;
			while(line[ind]!='\n'){
				while(line[ind]!=' '&&line[ind]!='\n'){
					tmp+=line[ind];
					ind++;
				}
				if(line[ind]=='.'){
					tmp+='.';
				}
				reverse(tmp);
				total+=tmp;
				if(line[ind]==' '){
					total+=' ';
				}
				tmp="";
				ind++;
				if(ind==line.size()) break;

			}
			cout<<total<<"\n";
			total="";
			line="";
		}
	}
	total="";
	if(cin.eof()&&line.compare("")!=0){
			string tmp="";
			int ind=0;
			while(line[ind]!='\n'&&line[ind]!=0){
				while(line[ind]!=' '&&line[ind]!='\n'&&line[ind]!=0){
					tmp+=line[ind];
					ind++;
				}
				if(line[ind]=='.'){
					tmp+='.';
				}
				reverse(tmp);
				total+=tmp;
				if(line[ind]==' '){
					total+=' ';
				}
				if(line[ind]==0) break;
				tmp="";
				ind++;
				if(ind==line.size()) break;
			}
			cout<<total<<"\n";
	}

	return 0;
}