#include<bits/stdc++.h>
using namespace std;

vector<string> ids;

void record(string id){
	ids.push_back(id);
}

string getId(int i){
	if(i>=ids.size())
		return "";
	return ids[ids.size()-1-i];
}


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string tmp;
		cin>>tmp;
		ids.push_back(tmp);
	}
	record("912039");
	int x;
	cin>>x;
	string s=getId(x);
	if(s==""){
		cout<<"No existe registro";
	}
	else cout<<s<<"\n";
	return 0;
}