#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;	
	TreeNode(int x) : val(x),left(NULL), right(NULL){}
};

bool leaf(TreeNode* root){
	return root->left==NULL&&root->right==NULL;
}

int Bigger(TreeNode* root){
	if(leaf(root)) return root->val;
	if(root->right==NULL){
		return root->val;
	}
	else
		return Bigger(root->right);
}

int SecondBigger(TreeNode* root){
	if(leaf(root)){
		return -1;
	}
	if(root->right==NULL){
		if(leaf(root->left)) return root->left->val;
		return Bigger(root->left);
	}
	if(leaf(root->right)){
		return root->val;
	}
	else{
		return SecondBigger(root->right);
	}
}

int main(){
	TreeNode* root=new TreeNode(60);
	root->left=new TreeNode(3);
	root->right=new TreeNode(74);
	root->right->left=new TreeNode(65);
	root->right->left->left=new TreeNode(63);
	root->right->left->right=new TreeNode(70);
	cout<<SecondBigger(root)<<"\n";
	return 0;
}