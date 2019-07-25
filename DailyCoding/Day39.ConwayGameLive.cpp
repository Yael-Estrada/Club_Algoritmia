#include<bits/stdc++.h>
using namespace std;

void nextGeneration(vector<vector<int>> &gen){
	vector<vector<int>> future;
	int n=gen.size(),m=gen[0].size();
	for(int i=0;i<n;i++){
		future.push_back(vector<int>(m));
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int neigh=0;
			if(j>0){
				if(i>0){
					if(gen[i-1][j-1]==1) neigh++;
				}
				if(gen[i][j-1]==1) neigh++;
				if(i<n-1){
					if(gen[i+1][j-1]) neigh++;
				}
			}
			if(i>0) if(gen[i-1][j]) neigh++;
			if(i<n-1) if(gen[i+1][j]) neigh++;
			
			if(j<m-1){
				if(i>0){
					if(gen[i-1][j+1]) neigh++;
				}
				if(gen[i][j+1]) neigh++;
				if(i<n-1){
					if(gen[i+1][j+1]) neigh++;
				}
			}
			if(gen[i][j]==1){
				if(neigh<2||neigh>3) future[i][j]=0;
				else future[i][j]=1;
			}
			else{
				if(neigh==3) future[i][j]=1;
				else future[i][j]=0;
			}

		}
	}

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(future[i][j]==1)
			cout<<"*"<<" ";
		else
			cout<<"."<<" ";
	}
	cout<<"\n";
}

}

int main(){
	vector<vector<int>> alives;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		alives.push_back(vector<int>(m));
		for(int j=0;j<m;j++){
			cin>>alives[i][j];
		}
	}
	nextGeneration(alives);
}
