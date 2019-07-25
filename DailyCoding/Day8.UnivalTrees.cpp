#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

Solution.
We create our structure to store the binary tree.
To know if the tree is unival we make a recursive function that test if the node is leaf then it is unival, if not we call 
recursively if the children subtrees are unival, then the actual node is unival.
To count the number of univals subtrees we did a BFS through the children of the node and count for each node if it is unival
we increase the counter one until our BFS queue is not empty. Complexity O(n^2).

To reduce the complexity i found an algorithm where the recursion only passes once for each node, so the complexity would be
O(n) where n is the number of nodes.
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isUnival(TreeNode* root){
	if(root==NULL) return true;
	if(root->right==NULL&&root->left==NULL)
		return true;
	bool b=true;
	if(root->left!=NULL){
		if(root->left->val==root->val&&isUnival(root->left)){
			b=true;
		}
		else{
			b=false;
		}
	}
	if(!b) return false;
	if(root->right!=NULL){
		if(root->right->val==root->val&&isUnival(root->right)){
			b=true;
		}
		else{
			b=false;
		}
	}
	return b;
}

int countUnivals(TreeNode* root){
	if(root==NULL) return 0;
	queue<TreeNode*> cola;
	cola.push(root);
	int unis=0;
	while(!cola.empty()){
		TreeNode* aux=cola.front();
		cola.pop();
		if(isUnival(aux)) unis++;
		if(aux->left!=NULL) cola.push(aux->left);
		if(aux->right!=NULL) cola.push(aux->right);
	}
	return unis;
}

//This function taken from DailyCodingProblem blog reduces the time complexity to O(n)

pair<int,bool> helper(TreeNode* root){
	if(root==NULL) return make_pair(0,true);
	pair<int,bool> left=helper(root->left);
	pair<int,bool> right=helper(root->right);
	int total=right.first+left.first;
	if(left.second&&right.second){
		if(root->left!=NULL&&root->val!=root->left->val){
			return make_pair(total,false);
		}
		if(root->right!=NULL&&root->val!=root->right->val){
			return make_pair(total,false);
		}
		return make_pair(total+1,true);
	}
	return make_pair(total,false);
}

int count(TreeNode* root){
	pair<int,bool> h=helper(root);
	return h.first;
}

int main(){
	TreeNode* root=new TreeNode('a');
	root->left=new TreeNode('c');
	root->right=new TreeNode('b');
	root->right->left=new TreeNode('b');
	root->right->right=new TreeNode('b');
	//root->right->left->left=new TreeNode(1);
	root->right->left->right=new TreeNode('b');
	cout<<count(root)<<"\n";
	return 0;
}