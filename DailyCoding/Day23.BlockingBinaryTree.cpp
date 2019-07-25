#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Google.

Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants 
or ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. 
Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. 
Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. 
You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. 
Each method should run in O(h), where h is the height of the tree.

Solution.
We only add a locked attribute to the binary tree nodes, and a parent TreeNode* pointer to the ancestor of the node, and 
to know  if it is locked we walk trough the node's subtrees and the parent node to know if any of them is locked.

To optimize the way to visit the nodes in O(h) where h is the heigh of the tree, we create an attribute that shows how many
nodes in the subtrees are locked, and when we lock, we add one to this attribute in all the ancestor's nodes, when we unlock
we substract one to the number of nodes locked of the ancestors.  
*/

struct TreeNode {
	int val;
	bool locked;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;	
	TreeNode(int x) : val(x), locked(false), left(NULL), right(NULL), parent(NULL) {}
};

bool isLocked(TreeNode* nodo){
	if(nodo==NULL) return false;
	if(nodo->left==NULL&&nodo->right==NULL){
		return nodo->locked;
	}
	if(nodo->locked==true) return true;
	bool b=isLocked(nodo->left),b1=isLocked(nodo->right),b2=false;
	return b||b1||nodo->parent->locked;
}

bool lock(TreeNode* nodo){
	if(isLocked(nodo)) return false;
	else
		nodo->locked=true;
	return true;
}

bool unlock(TreeNode* nodo){
	if(isLocked(nodo)&&nodo->locked==false) return false;
	else{
		nodo->locked=false;
		return true;
	}
}

int main(){
	TreeNode* root=new TreeNode(0);
	root->left=new TreeNode(1);
	root->left->parent=root;
	root->right=new TreeNode(2);
	root->right->parent=root;
	root->left->right=new TreeNode(3);
	root->left->right->parent=root->left;
	root->right->left=new TreeNode(4);
	root->right->left->parent=root->right;
	root->right->right=new TreeNode(5);
	root->right->right->parent=root->right;
	root->right->left->left=new TreeNode(6);
	root->right->left->left->parent=root->right->left;

	lock(root->right->left->left);
	cout<<isLocked(root->right)<<"\n";
}

