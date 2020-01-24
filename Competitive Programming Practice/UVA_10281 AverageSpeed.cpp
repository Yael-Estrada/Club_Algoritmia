/*	UVA 10281 (Ad Hoc)	Average Speed 	Yael Estrada
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	string cad;
	double vel=0,velant;
	double distTotal=0;
	int act=0;
	int ini=0,fin;
	while(getline(cin,cad)){
		const char *input=cad.c_str();
		int hora,min,seg;
		
		sscanf(input,"%d:%d:%d",&hora,&min,&seg);
		if(cad[8]!='\0'){
			string v="";
			for(int i=9;cad[i]!='\0';i++){
				v+=cad[i];
			}
			velant=vel;
			vel=(double)stoi(v)/3600;
			fin=seg+(hora*3600)+(min*60);
			if(act!=0){
				distTotal+=(fin-ini)*velant;
			}
			act++;
		}
		else{
			fin=seg+(hora*3600)+(min*60);
			distTotal+=(fin-ini)*vel;
			printf("%02d:%02d:%02d %.2lf km\n",hora,min,seg,distTotal);

		}
		ini=fin;
	}
	return 0;
}