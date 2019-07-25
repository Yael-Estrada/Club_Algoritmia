#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.

Solution.
https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/
*/

float estimatePI(int iter){
	int circlePts,squarePts;
	srand(time(NULL));
	for(int i=0;i<iter;i++){
		float x=((float) rand() / (RAND_MAX));
		float y=((float) rand() / (RAND_MAX));
		float r=x*x+y*y;
		if(r<=1) circlePts++;
		squarePts++;
	}
	return 4*((float)circlePts/(float)squarePts);
}

int main(){
	int iterations;
	cin>>iterations;
	float f=estimatePI(iterations);
	cout<<fixed<<setprecision(3)<<f<<"\n";

}