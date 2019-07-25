#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Quora.

Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible 
anywhere in the word. If there is more than one palindrome of minimum length that can be made, return the lexicographically 
earliest one (the first one alphabetically).

For example, given the string "race", you should return "ecarace", since we can add three letters to it 
(which is the smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" 
by adding three letters, but "ecarace" comes first alphabetically.

Solution.
Use a DP map to store the values of calculate the function for the substring "s", where |s|<=original string size
The base cases for the recursive function are when it has only one character return 1, or if it has 2 characters, compare
if both are equal.
Then call the recursive funcion, 
if the first and last char are equal, call the function with a substring that starts in the char
1 and the previous of the last char
else call the funcion and get the minimum of a substring that starts in 1 or the substring that ends in s.size()-1, then add
it one and return that result.
Remember to store the results of every substring in the DP map.
*/

map<string,int> passed;

// int minPalindrome(string str)  
// {  	int n=str.size();
//     // Create a table of size n*n. table[i][j]  
//     // will store minimum number of insertions  
//     // needed to convert str[i..j] to a palindrome.  
//     int table[n][n], l, h, gap;  
  
//     // Initialize all table entries as 0  
//     memset(table, 0, sizeof(table));  
  
//     // Fill the table  
//     for (gap = 1; gap < n; ++gap)  
//         for (l = 0, h = gap; h < n; ++l, ++h)  
//             table[l][h] = (str[l] == str[h])?  
//                         table[l + 1][h - 1] :  
//                         (min(table[l][h - 1],  
//                              table[l + 1][h]) + 1);  
  
//     // Return minimum number of insertions 
//     // for str[0..n-1]  
//     return table[0][n - 1];  
// }  

int minPalindrome(string s){
	if(s.size()==0||s.size()==1) return 0;
	if(s.size()==2){
		passed.insert(make_pair(s,s[0]==s[1]? 0:1));
		return passed[s];
	}
	if(passed.count(s)!=0) return passed[s];
	int ini=0,fin=s.size()-1;
	if(s[ini]==s[fin]){
		passed.insert(make_pair(s,minPalindrome(s.substr(1,s.size()-2))));
		return passed[s];
	}
	passed.insert(make_pair(s,1+min(minPalindrome(s.substr(1,s.size()-1)),minPalindrome(s.substr(0,s.size()-1)))));
	return passed[s]; 
}

int main(){
	string s;
	cin>>s;
	cout<<minPalindrome(s)<<"\n";
	return 0;
}