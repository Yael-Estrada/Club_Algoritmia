#include<bits/stdc++.h>
using namespace std;

int mayor(vector<string> &files){
	int mx=INT_MIN;
	for(int i=0;i<files.size();i++){
		if(files[i].size()>mx){
			mx=files[i].size();
		}
	}
	return mx;
}

vector<string> split(string s){
	string tmp="";
	vector<string> res;
	for(int i=0;i<s.size();i++){
		if(s[i]=='\\'){
			if(s[i+1]=='n'){
				res.push_back(tmp);
				tmp="";
				i++;
			}
			else{
				if(s[i+1]=='t'){
					i++;
					tmp+="\t";
				}
			}
		}
		else
			tmp+=s[i];
	}
	res.push_back(tmp);
	return res;
}

int count(string s){
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='\t'){
			x++;
		}
	}
	return x;
}

int longestPath(string path){
	vector<string> archivos=split(path);
	string file="";
	int maxsize=0;
	int nivelact=-1;
	stack<string> lastPath;
	for(int i=0;i<archivos.size();i++){
		int nivel=count(archivos[i]);
		int size=file.size();
		if(nivel>nivelact){
			nivelact=nivel;
			lastPath.push(archivos[i].substr(nivel,archivos[i].size()-nivel));
			file+=lastPath.top();
			if(lastPath.top().find(".")==string::npos)
				file+="/";
		}
		else{
			if(nivel==nivelact){
				if(lastPath.top().find(".")==string::npos)
						file=file.substr(0,file.size()-lastPath.top().size()-1);
					else
						file=file.substr(0,file.size()-lastPath.top().size());
				lastPath.pop();
				lastPath.push(archivos[i].substr(nivel,archivos[i].size()-nivel));
				file+=lastPath.top();
				if(lastPath.top().find(".")==string::npos)
					file+="/";
			}
			else{
				while(nivelact!=nivel){
					if(lastPath.top().find(".")==string::npos)
						file=file.substr(0,file.size()-lastPath.top().size()-1);
					else
						file=file.substr(0,file.size()-lastPath.top().size());
					lastPath.pop();
					nivelact--;
				}
				i--;
			}
		}
		size=file.size();
		if(size>maxsize&&lastPath.top().find(".")!=string::npos) maxsize=size;
	}
	return maxsize;
}

int main(){
	string path;
	getline(cin,path);
	cout<<longestPath(path)<<"\n";
	return 0;
}