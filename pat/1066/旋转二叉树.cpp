#include<iostream>
using namespace std;
struct nood{
	int value;
	struct nood *left,*right;
};
nood *toleft(nood *root){
	nood *t=root->right;
	root->right=t->left;
	t->left=root;
	return t;
}
nood *toright(nood *root){
	nood *t=root->left;
	root->left=t->right;
	t->right=root;
	return t;
}
nood *lefttoright(nood *root){
	root->left=toleft(root->left);
	 return toright(root);
}
nood *righttoleft(nood *root){
	root->right=toright(root->right);
	return toleft(root);
}
int gethigh(nood *root){
	if(root==NULL) return 0;
	return max(gethigh(root->left),gethigh(root->right))+1;
}
nood *insert(nood *root,int value){
	if(root==NULL){
		root=new nood();
		root->value=value;
		root->left=root->right=NULL;
	}else if(value<root->value){
		root->left=insert(root->left,value);
		if(gethigh(root->left)-gethigh(root->right)==2){
			root=value < root->left->value?toright(root) : lefttoright(root);
		}
	}else{
		root->right=insert(root->right,value);
		if(gethigh(root->left)-gethigh(root->right)==-2){
			root=value > root->right->value?toleft(root) : righttoleft(root);
		}
	}
	return root;
}
int main(){
	int n,a;
	scanf("%d",&n);
	nood *root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		root=insert(root,a);
	}
	printf("%d",root->value);
	return 0;
}
