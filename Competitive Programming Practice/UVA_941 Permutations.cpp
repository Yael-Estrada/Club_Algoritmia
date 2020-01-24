/* @brief	(Ad-Hoc) UVA 941 - Permutations		Yael Estrada
*/

#include<bits/stdc++.h>
using namespace std;

#define MAXN 21
long long fac[MAXN];
void precalcular(){
	fac[0]=1;
	for(int i=1;i<MAXN;i++){
		fac[i]=fac[i-1]*i;
	}
}

string NthPermutation(string s,long long int n){
	int freq[26];
	memset(freq,0,sizeof(freq));
	for(int i=0;i<s.size();i++){
		freq[s[i]-'a']++;
	}
	int len=s.size();
	long long int sum=0;
	string output="";
	while(output.size()!=s.size()-1){
		for(int i=0;i<26;i++){
			int k=output.size();
			if(freq[i]==0) continue;
			for(int j=0;j<freq[i];j++){
				sum+=fac[len-1-k];
				if(sum>=n){
					sum-=fac[len-1-k];
					output+=(char)(i+'a');
					freq[i]--;
					break;
				}
			}
			if(output.size()>k) break;
		}
	}
	for(int i=0;i<26;i++){
		if(freq[i]!=0){
			output+=(char)(i+'a');
		}
	}
	return output;
}

int main(){
	int samples;
	cin>>samples;
	precalcular();
	while(samples--){
		string s;
		long long int n;
		cin>>s>>n;
		cout<<NthPermutation(s,n+1)<<"\n";
	}
	return 0;
}