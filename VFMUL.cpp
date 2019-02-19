/*********** 		SPOJ VFMUL-"Very Fast Multiplication"	FFT 			***********/
/*********** 				Yael Estrada					***********/

#include<bits/stdc++.h>
using namespace std;
using comp = complex<double>;
using lli = long long int;
const double PI = acos(-1.0);

int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}

void fft(vector<comp> & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	for(int k = 1; k < n; k <<= 1){
		//wk is a 2k-th root of unity
		comp wk = polar(1.0, PI / k * inv);
		for(int i = 0; i < n; i += k << 1){
			comp w(1);
			for(int j = 0; j < k; ++j, w = w * wk){
				comp t = X[i + j + k] * w;
				X[i + j + k] = X[i + j] - t;
				X[i + j] += t;
			}
		}
	}
	if(inv == -1)
		for(int i = 0; i < n; ++i)
			X[i] /= n;
}

void multiply(vector<comp> &A,vector<comp> &B){
	int degree=nearestPowerOfTwo(max(A.size(),B.size()))<<1;
	A.resize(degree);
	B.resize(degree);
	fft(A,1);
	fft(B,1);
	for(int i=0;i<degree;i++){
		A[i]*=B[i];
	}
	fft(A,-1);
}

int main(){
	string num1;
	string num2;
	cin>>num1>>num2;
	vector<comp> arr1,arr2;
	for(lli i=0;i<num1.size();i++){
		arr1.push_back(num1[i]-'0');
	}
	for(lli i=0;i<num2.size();i++){
		arr2.push_back(num2[i]-'0');
	}
	multiply(arr1,arr2);
	int sum=0;
	int res=0;
	int pot=1;
	for(lli i=arr1.size()-1;i>=0;i--){
		sum+=((res+arr1[i])%10)*pow(10,pot);
		res=arr1[i]/10;
		pot*=10;
	}
	cout<<sum<<endl;
	return 0;
}
