#include<bits/stdc++.h>
using namespace std;

/*
This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, 
and deserialize(s), which deserializes the string back into the tree

Solution.
We create an structure in order to connect all the nodes of the tree, it is called TreeNode, to serialize we use BFS
we create a queue of Nodes and we visit each one starting from the root, and while we are visiting nodes, we add them to the
queue, and finally we get a string with all the values of the tree separated by a coma.
To deserialize its the same idea, we split the string separating the tokens between comas and parenthesis, and then with the
vector of integers we call BFS to create a node and pop an integer from the vector, then we do this with their children and
we add them to a queue in order to process the nodes in the orden root left right...
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void ImpArbol(TreeNode* root){
	if(root==NULL) return;
	cout<<root->val<<"\n";
	ImpArbol(root->left);
	ImpArbol(root->right);
}
string serialize(TreeNode* root) {
    string res="[";
    queue<TreeNode*> cola;
    cola.push(root);
    while(!cola.empty()){
        TreeNode* aux=cola.front();
        cola.pop();
        if(aux==NULL){
            res+="null,"; 
            continue;
        }
        res+=to_string(aux->val)+",";
        cola.push(aux->left);
        cola.push(aux->right);
    }
    res[res.size()-1]=']';
    return res;
}

vector<int> desempaquetar(string dato){
	vector<int> n;
	string cad="";
	for(int i=1;i<dato.size();i++){
		if(dato[i]==','||dato[i]==']'){
			if(cad.compare("null")==0){
				n.push_back(INT_MIN);
				cad="";
				continue;
			}
			n.push_back(stoi(cad));
			cad="";
		}
		else{
			cad+=dato[i];
		}
	}
	return n;
}



TreeNode* armarArbol(vector<int> &data){
	int i=0;
	queue<TreeNode*> creados;
	TreeNode* n=new TreeNode(data[i++]);
	creados.push(n);
	
	while(i<data.size()){
		TreeNode* act=creados.front();
		creados.pop();
		if(data[i]!=INT_MIN){
			act->left=new TreeNode(data[i++]);
			creados.push(act->left);
		}
		else{
			i++;
		}
		if(i==data.size()) break;
		if(data[i]!=INT_MIN){
			act->right=new TreeNode(data[i++]);
			creados.push(act->right);
		}
		else i++;
	}
	return n;
}

TreeNode* deserialize(string data) {
	vector<int> nodos=desempaquetar(data);      
	int i=0;
	TreeNode* arbol;
	arbol=armarArbol(nodos);
	return arbol;
}

int main(){
	TreeNode* root=new TreeNode(2);
	root->left=new TreeNode(3);
	root->right=new TreeNode(4);
	root->right->left=new TreeNode(7);
	string r=serialize(root);
	cout<<r<<"\n";
	TreeNode* root2=deserialize(r);
	ImpArbol(root2);

	return 0;
}