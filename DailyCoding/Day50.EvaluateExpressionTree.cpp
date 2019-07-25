#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	string val;
	TreeNode* left;
	TreeNode* right;	
	TreeNode(string x) : val(x), left(NULL), right(NULL) {}
};

int evaluar(TreeNode* root){
	if(root->val=="+"){
		return evaluar(root->left)+evaluar(root->right);
	}
	if(root->val=="-"){
		return evaluar(root->left)-evaluar(root->right);
	}
	if(root->val=="*"){
		return evaluar(root->left)*evaluar(root->right);
	}
	if(root->val=="/"){
		return evaluar(root->left)/evaluar(root->right);
	}
	return stoi(root->val);
}

int main(){
	TreeNode* root=new TreeNode("*");
	root->left=new TreeNode("+");
	root->right=new TreeNode("+");
	root->left->left=new TreeNode("3");
	root->left->right=new TreeNode("2");
	root->right->left=new TreeNode("4");
	root->right->right=new TreeNode("5");
	int r=evaluar(root);
	cout<<r<<"\n";
}