#include<bits/stdc++.h>
using namespace std;

// UVA-573	"The Snail"	Yael Estrada

int main(){
	float H,D,U,F;
	
	while(cin>>H>>U>>D>>F&&(D&&U&&H&&F)){
		int day=1;
		double factor=(U*F)/100;
		double pos=0;
		double dist=U;
		int success=1;
		while(1){
			pos+=dist;

			if(day!=0) dist-=factor;

			if(dist<0) dist=0;
			
			if(pos>H) break;
			pos-=D;
			
			if(pos<0){ success=0; break;}
			day++;
		}
		if(!success){
			cout<<"failure on day "<<day<<"\n";
		}
		else{
			cout<<"success on day "<<day<<"\n";
		}
	}
	return 0;
}