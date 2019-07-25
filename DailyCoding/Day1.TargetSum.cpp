#include<bits/stdc++.h>
using namespace std;

/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass? (O(n))

Solution.
We store all the numbers of the array in a unordered_set because of his linear search
The way to store the numbers is the following:
If the complement of the number (target less that number) is in the set, we return true because adding both we get the sum 
target
Else we insert that number in the set.
Finally if we have inserted all numbers into the set, we return false because the sum cant be obtained.
*/

bool canSum(vector<int> &nums,int target){
    unordered_set<int> comp;
    for(int i=0;i<nums.size();i++){
        if(comp.count(target-nums[i])!=0){
            return true;
        }
        else{
            comp.insert(nums[i]);
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    bool b=canSum(nums,target);
    if(b)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}