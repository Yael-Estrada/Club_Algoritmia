#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> par;

/************** 		SPOJ	"The Knapsack Problem"	DP Algorithm 		*****************/
/*************					Yael Estrada				****************/

void MergeSort(par* a, int low, int high);
void Merge(par* a, int low, int high, int mid);

//first=w second=v
int KS(par* items,int n,int peso){
	int resto;
	int pesos[peso+1];
	for(int i=0;i<peso+1;i++){
		pesos[i]=i;
	}
	int tabla[n][peso+1];
	for(int i=0;i<n;i++){
		tabla[i][0]=0;
	}
	for(int i=0;i<peso+1;i++){
		tabla[0][i]=0;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<peso+1;j++){
			tabla[i][j]=0;
			if(items[i].second>pesos[j]){
				tabla[i][j]=tabla[i-1][j];
			}
			if(items[i].second==pesos[j]){
				tabla[i][j]=max(tabla[i-1][j],items[i].first);
			}
			if(items[i].second<pesos[j]){
				resto=pesos[j]-items[i].second;
				tabla[i][j]=items[i].first;
				tabla[i][j]+=tabla[i-1][resto];
				if(tabla[i-1][j]>tabla[i][j])
					tabla[i][j]=tabla[i-1][j];
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<peso+1;j++){
	// 		cout<<tabla[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	return tabla[n-1][peso];
}

int main(){
int weight,n,tmp1,tmp2;
cin>>weight>>n;
par items[n+1];
items[0]=make_pair(0,0);
for(int i=1;i<n+1;i++){
	cin>>tmp1>>tmp2;
	items[i]=make_pair(tmp2,tmp1);
}
MergeSort(items,0,n);
// for(int i=0;i<n;i++){
// 	cout<<items[i].first<<" "<<items[i].second<<endl;
// }
int knapsack=KS(items,n+1,weight);
cout<<knapsack<<"\n";
}

void Merge(par* a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k;
	par temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i].second < a[j].second)
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			if(a[i].second==a[j].second){
				if(a[i].first<a[j].first){
					temp[k] = a[i];
					k++;
					i++;
				}
				else{
					temp[k] = a[j];
					k++;
					j++;
				}
			}
			else{
			temp[k] = a[j];
			k++;
			j++;
			}
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(par* a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
