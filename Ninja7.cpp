#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;


/****************  		SPOJ NINJA7-"Two Sequences Problem"	Greedy Algorithm 	****************/
/**************** 				Yael Estrada					****************/
int main(){
	int n,T;
	cin>>T;
	while(T--){
		cin>>n;
		vector<par> arr(n);
		vector<int> vec;
		for(long long int i=0;i<n;i++){
			cin>>arr[i].first;
		}
		for(long long int i=0;i<n;i++){
			cin>>arr[i].second;
		}
		long long int suma=0,maxim=0;
		for(long long int i=n-1;i>=0;i--){
			int dif=arr[i].first-arr[i].second;
			if(dif>=0){
				maxim++;
				suma+=dif;
			}
			else{
				vec.push_back(-dif);
			}
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++){
			if(vec[i]>suma){
				break;
			}
			maxim++;
			suma-=vec[i];
		}
		cout<<maxim<<endl;
	}

	return 0;
}
