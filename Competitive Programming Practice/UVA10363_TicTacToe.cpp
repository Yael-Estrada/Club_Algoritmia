/* @brief UVA 10363 (Ad Hoc) Tic Tac Toe 	Yael Estrada
*/
#include<bits/stdc++.h>
using namespace std;

pair<int,char> ganada(vector<vector<char>> &table){
	char c=table[0][0];
	int winsx=0,winso=0;
	for(int i=0;i<3;i++){
		if(table[i][i]=='.') break;
		if(table[i][i]!=c) break;
		if(i==2){
			if(c=='O') winso++;
			if(c=='X') winsx++;
		}
	}
	c=table[0][2];
	for(int i=0;i<3;i++){
		if(table[i][2-i]=='.') break;
		if(table[i][2-i]!=c) break;
		if(i==2){
			if(c=='O') winso++;
			if(c=='X') winsx++;
		}
	}

	for(int i=0;i<3;i++){
		if(table[i][0]=='.'||table[i][1]=='.'||table[i][2]=='.') continue;
		if(table[i][0]==table[i][1]&&table[i][1]==table[i][2]){
			if(table[i][0]=='O') winso++;
			if(table[i][0]=='X') winsx++;
		}
	}
	for(int i=0;i<3;i++){
		if(table[0][i]=='.'||table[1][i]=='.'||table[2][i]=='.') continue;
		if(table[0][i]==table[1][i]&&table[1][i]==table[2][i])
		{
			if(table[0][i]=='O') winso++;
			if(table[0][i]=='X') winsx++;
		}
	}
	if(winso>winsx){
		if(winsx==0&&winso>=1){
			return make_pair(1,'O');
		}
		return make_pair(winso+winsx,'O');
	}
	else{
		if(winso==0&&winsx>=1)
			return make_pair(1,'X');
		return make_pair(winsx+winso,'X');
	}
}
string isValid(vector<vector<char>> &table){
	int x=0,o=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(table[i][j]=='X'){
				x++;
			}
			else{
				if(table[i][j]=='O'){
					o++;
				}
			}
		}
	}
	
	if(x==o||o+1==x){
		pair<int,char> w=ganada(table);
		//cout<<w.first<<" "<<w.second<<"\n";
		if(w.first==1){
			if(w.second=='X'){
				if(o+1==x) return "yes";
				else{
					return "no";
				}
				
			}
			else{
				if(o==x) return "yes";
				else{
					return "no";
				}
			}
		}
		if(w.first>1) return "no";
		return "yes";
	}
	return "no";
}

int main(){
	int t;
	cin>>t;
	vector<vector<char>> table(3);
	for(int te=0;te<3;te++){
		table[te]=vector<char>(3);
	}
	for(int te=0;te<t;te++){
		string tmp;
		if(te){
			cin.ignore();
		}
		for(int i=0;i<3;i++){
			cin>>tmp;
			table[i][0]=tmp[0];
			table[i][1]=tmp[1];
			table[i][2]=tmp[2];
		}
		cout<<isValid(table)<<"\n";
	}
	return 0;
}