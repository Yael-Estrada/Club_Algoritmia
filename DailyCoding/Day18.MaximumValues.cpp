#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray 
of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. 
You can simply print them out as you compute them.

Solution.
We create an auxiliar array of k size where we store the first k elements of the array, then we calculate the max of that 
elements, for each next value we replace it in the position of the first actual value inserted of those which stills in the
auxiliary array. We print the max value of the aux array every time we add a new value, so the complexity would be
O(n+(n-k)k)-> O(nk)

Optimal Solution.
Using a deque we mantain in the front of the deque the max element of the k first elements, the other ones we can pop them, then
for each value next of the first k elements we pop the values that are already visited and in a range farther than i-k, then
we use the same idea of maintain the max value in the front of the queue and we pop the values that are less than the value
that actually we try to insert.

*/

void printMayores(vector<int> &ar,int k){
	deque<int> cola;
	for(int i=0;i<k;i++){
		while(!cola.empty()&&ar[cola.back()]<=ar[i])
			cola.pop_back();
		cola.push_back(i);
	}
	for(int i=k;i<ar.size();i++){
		cout<<ar[cola.front()]<<" ";
		while(!cola.empty()&&cola.front()<=i-k){
			cola.pop_front();
		}
		while(!cola.empty()&&ar[cola.back()]<=ar[i]){
			cola.pop_back();
		}
		cola.push_back(i);
	}
	cout<<ar[cola.front()]<<" ";
}

// void printMayor(vector<int> &k){
// 	int mx=INT_MIN;
// 	for(int i=0;i<k.size();i++){
// 		if(mx<k[i]){
// 			mx=k[i];
// 		}
// 	}
// 	cout<<mx<<" ";
// }

// void printMayores(vector<int> &ar,int& k){
// 	vector<int> aux(k);
// 	int apaux=0;
// 	for(int i=0;i<k;i++){
// 		aux[i]=ar[i];
// 	}
// 		printMayor(aux);
// 	for(int i=k;i<ar.size();i++){
// 		aux[apaux]=ar[i];
// 		apaux=(apaux+1)%k;
// 		printMayor(aux);
// 	}

// }


int main(){
	int n,k;
	cin>>n;
	vector<int> array(n);
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	cin>>k;
	printMayores(array,k);
	cout<<endl;
}