#include<bits/stdc++.h>
using namespace std;

/*

Solution.
To solve this problem we have a matrix of N*K cells, we create a matrix with the same size in rows and columns
The first row is the same that the origin matrix, but from the second to the last row we follow this algorithm.
We search the minimum cost from the previous row.
The ith row is calculated adding the min value of the ith-1 row and the value in the ith row jth column, we store the value
in that cell.
We iterate over the rows and we return the minimum value of the last row.
*/

int minWaysToPaint(vector<vector<int>> &casas){
	int mincost=INT_MAX,indant;
	vector<vector<int>> costos(casas.size());
	for(int i=0;i<casas[0].size();i++){
		costos[0].push_back(casas[0][i]);
		if(costos[0][i]<mincost){
			mincost=costos[0][i];
			indant=i;
		}
	}
	for(int i=1;i<casas.size();i++){
		int act=INT_MAX;
		for(int j=0;j<casas[i].size();j++){
			costos[i].push_back(mincost+casas[i][j]);
			if(costos[i][j]<act&&indant!=j){
				act=costos[i][j];
				indant=j;
			}
		}
		mincost=act;
	}
	return mincost;
}


int main(){
	int N,K;
	cin>>N>>K;
	vector<vector<int>> casas;
	for(int i=0;i<N;i++){
		casas.push_back(vector<int>(K));
		for(int j=0;j<K;j++){
			cin>>casas[i][j];
		}
	}

	cout<<minWaysToPaint(casas)<<"\n";
}