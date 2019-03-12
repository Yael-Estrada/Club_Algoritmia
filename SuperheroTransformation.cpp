#include<bits/stdc++.h>
using namespace std;

/************** Codeforces	-	"Superhero Transformation"		*********************/
/**************					Yael Estrada					*********************/

string sepuede(string a,string b,set<char> vow,set<char> cons){
	int eska,eskb,esva,esvb;
	if(a.size()!=b.size()) return "NO";
	for(int i=0;i<a.size()&&i<b.size();i++){
	esva=vow.count(a[i]);
	esvb=vow.count(b[i]);
	eska=cons.count(a[i]);
	eskb=cons.count(b[i]);
	if(eska&&esvb){
		return "NO";
	}
	if(eskb&&esva){
		return "NO";
	}
	}

	return "YES";
}

int main(){
	string a,b;
	cin>>a>>b;
	set<char>	vowels,cons;
	for(int i=97;i<123;i++){
		if(i==97||i==101||i==105||i==111||i==117){
			vowels.insert(i);
		}
		else{
			cons.insert(i);
		}
	}
	cout<<sepuede(a,b,vowels,cons)<<"\n";


}