/* @brief	(Ad-Hoc) UVA 837 - Light and Transparencies		Yael Estrada
*/
#include<bits/stdc++.h>
using namespace std;
#define FLOAT_MAX numeric_limits<float>::max() 
#define FLOAT_MIN numeric_limits<float>::min() 
typedef pair<int,int> pii;
typedef pair<float,float> pff;

struct segmento{
	double ini,fin;
	double trans;
};

vector<segmento> Transparencias(vector<segmento> &x,vector<float> &ejex){
	vector<segmento> res;
	segmento s;
	float trans=1.0;
	for(int i=0;i<ejex.size();i++){
		if(i==0){
			s.ini=FLOAT_MIN;
			s.fin=ejex[i];
			s.trans=1.0;
			res.push_back(s);
			continue;
		}
		trans=1.0;	
		for(int j=0;j<x.size();j++){
			if(x[j].ini<=ejex[i-1]&&x[j].fin>=ejex[i]){
				trans*=x[j].trans;
			}
		}
		s.ini=ejex[i-1];
		s.fin=ejex[i];
		s.trans=trans;
		res.push_back(s);
		if(i==ejex.size()-1){
			s.ini=ejex[i];
			s.fin=FLOAT_MAX;
			s.trans=1.0;
			res.push_back(s);
			continue;
		}
	}
	return res;
}

bool sortSegments(segmento &first,segmento &sec){
	if(first.ini<sec.ini){
		return true;
	}
	if(first.ini==sec.ini){
		if(first.fin<first.fin){
			return true;
		}
	}
	return false;
}

int main(){
	int tests;
	cin>>tests;
	cin.ignore();
	while(tests--){
		cin.ignore();
		int segments;
		cin>>segments;
		vector<segmento> x; 
		vector<float> ejex;
		float s1,s2,s3,s4,s5;
		for(int i=0;i<segments;i++){
			cin>>s1>>s2>>s3>>s4>>s5;
			segmento s;
			s.ini=min(s1,s3);
			s.fin=max(s1,s3);
			s.trans=s5;
			x.push_back(s);
			ejex.push_back(min(s1,s3));
			ejex.push_back(max(s1,s3));
		}
		sort(ejex.begin(),ejex.end());
		sort(x.begin(),x.end(),sortSegments);
		vector<segmento> res=Transparencias(x,ejex);
		cout<<res.size()<<"\n";
		for(int i=0;i<res.size();i++){
			if(i==0){
				cout<<"-inf ";
			}
			else{
				printf("%.3f ",res[i].ini);
			}
			if(i==res.size()-1){
				cout<<"+inf"<<" ";
			}
			else{
				printf("%.3f ",res[i].fin);
			}
			printf("%.3f\n",res[i].trans);
		}
		if(tests)
			cout<<"\n";
	}
	return 0;
}