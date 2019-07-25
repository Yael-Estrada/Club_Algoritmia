#include<bits/stdc++.h>
using namespace std;

/*

Solution.
First we sort the vector of pairs 
Create a vector of classrooms where we will store the time that it will be disoccupied at the moment of the pair i
for each pair i we look for a classroom which will be free at the beginning of the pair i, if we find it we update
the time that classrom ends to the end of pair i
if we dont find any classroom free we add a new classroom with the end of pair i.

*/

bool ordenar(pair<int,int> &uno,pair<int,int> &dos){
	if(uno.second<dos.second){
		return true;
	}
	else{
		if(uno.second==dos.second){
			if(uno.first<dos.first) return true;
		}
	}
	return false;
}

int classrooms(vector<pair<int,int>> &vec){
	sort(vec.begin(),vec.end());
	vector<int> clas;
	for(int i=0;i<vec.size();i++){
		int ini=vec[i].first,fin=vec[i].second;
		
		if(clas.size()==0) clas.push_back(fin);
		else{
			int j;
			for(j=0;j<clas.size();j++){
				if(ini<clas[j]) continue;
				else{
					clas[j]=fin;
					break;
				}
			}
			if(j==clas.size())
				clas.push_back(fin);
		}
	}

	return clas.size();
}

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> elems;
	int tmp1,tmp2;
	for(int i=0;i<n;i++){
		cin>>tmp1>>tmp2;
		elems.push_back(make_pair(tmp1,tmp2));
	}
	cout<<classrooms(elems)<<"\n";
}