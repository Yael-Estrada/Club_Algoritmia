#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left,*right;
	TreeNode(int x) : val(x),left(NULL), right(NULL){}
};

TreeNode* cons(int &ap,vector<int> &pre,vector<int> &in){
	if(in.size()==1) return new TreeNode(pre[ap++]);
	TreeNode* root=new TreeNode(pre[ap++]);
	int fin,ind;
	for(int i=0;i<in.size();i++){
		if(in[i]==root->val){
			ind=i; break;
		}
	}
	vector<int> izq(in.begin(),in.begin()+ind);
	vector<int> der(in.begin()+ind+1,in.end());
	root->left=cons(ap,pre,izq);
	root->right=cons(ap,pre,der);
	return root;
}

TreeNode* reconstruct(vector<int> &pre,vector<int> &in){
	int ap=0;
	if(pre.size()==0) return NULL;
	if(pre.size()==1) return new TreeNode(pre[0]);
	return cons(ap,pre,in);
}


void ImpPreorder(TreeNode* root){
	cout<<root->val<<"\n";
	if(root->left!=NULL)
		ImpPreorder(root->left);
	if(root->right!=NULL)
		ImpPreorder(root->right);
}

int main(){
	int n;
	cin>>n;
	vector<int> preorder(n);
	vector<int> inorder(n);
	for(int i=0;i<n;i++){
		cin>>preorder[i];
	}
	for(int i=0;i<n;i++){
		cin>>inorder[i];
	}
	TreeNode* root=reconstruct(preorder,inorder);
	ImpPreorder(root);
}