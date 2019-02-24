#include<bits/stdc++.h>
using namespace std;

/*********** 		UVA 12405 "Scarecrow" Greedy Algorithm 		**********/
/***********				Yael Estrada			*********/

int main(){
	int tests;
	cin>>tests;
	for(int j=0;j<tests;j++){
		int n;
		cin>>n;
		vector<char> campo(n);
		for(int i=0;i<n;i++){
			cin>>campo[i];
		}
		long long scare=0,act=0;
		for(int i=0;i<n;i++){
			if(campo[i]=='.'){
				if(act==0){
					scare++;
					act=1;
				}
				else{
					if(campo[i+1]=='.'){
						i++;
						act=0;
					}
					else{
						act=0;
					}
				}
			}
			else{
				if(act==0){
					continue;
				}
				else{
					if(campo[i+1]=='.'){
						i++;
						act=0;
					}
					else{
						act=0;
					}
				}

			}
		}
		cout<<"Case "<<j+1<<": "<<scare<<endl;

	}
	return 0;
}
