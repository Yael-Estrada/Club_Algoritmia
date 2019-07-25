#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. 
Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

Solution.
We are looking for the number of ways that we can represent the 4 by the sum of the numbers of options of steps that we can do.
So, for each option, to know the number of ways to climb the staircase with Xi steps at the time, we look for the number of ways
that we can climb the staircase N-Xi, we do this recursively with N, N-Xi,N-Xi+1,N-Xi+m and when we reach 0 is when we found
a way to climb the ladder using that sequency
Where N is the size of the staircase and m is the size of the array of steps.

Due to this approximation has a complexity of O(m^n), we need to reduce the complexity so we declare a memory array which 
keeps the number of ways to climb the first 'm' stairs of the ladder, and we shouldnt recalculate again many operations that we 
need to keep in the future.
This example is similar to a Fibbonacci series.

*/

long long int mem[10000];

long long int numWays(int n,vector<int>& steps){
	if(mem[n]!=-1) return mem[n];
	if(n<0) return 0;
	long long int sum=0;
	for(int i=0;i<steps.size();i++){
		sum+=numWays(n-steps[i],steps);
	}
	return mem[n]=sum;

}

int main(){
	int n;
	cin>>n;
	int steps;
	cin>>steps;
	for(int i=0;i<=n;i++){
		mem[i]=-1;
	}
	mem[0]=1;
	vector<int> pasos(steps);
	for(int i=0;i<steps;i++){
		cin>>pasos[i];
	}
	cout<<numWays(n,pasos)<<"\n";

}