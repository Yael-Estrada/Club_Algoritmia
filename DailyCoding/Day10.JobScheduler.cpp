#include<bits/stdc++.h>
using namespace std;
typedef void (v)();

void f(){
	cout<<"Job Scheduler!\n";
}

void f2(){
	cout<<"Planeador de trabajos!\n";
}

void scheduler(v *param,int n){
	this_thread::sleep_for(chrono::milliseconds(n));
	cout<<"Dormi "<<n<<" milisegundos!\n";
	param();
}

int main(){
	int n;
	cin>>n;
	scheduler(f2,n);
	scheduler(f,n);
}