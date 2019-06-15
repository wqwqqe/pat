#include<iostream>
using namespace std;
struct node{
	int l,r;
}a[100];
int maxn=0,ans;
void dfs(int root,int index){
	if(index>maxn){
		maxn=index;
		ans=root;
	}
	if(a[root].l!=-1) dfs(a[root].l,2*index);
	if(a[root].r!=-1) dfs(a[root].r,2*index+1);
}
int main(){
	int n,root=0;
	scanf("%d",&n);
	int have[100]={0};
	for(int i=0;i<n;i++){
		string l,r;
		cin>>l>>r;
		if(l!="-"){
			a[i].l=stoi(l);
			have[stoi(l)]=1;
		}else{
			a[i].l=-1;
		}
		if(r!="-"){
			a[i].r=stoi(r);
			have[stoi(r)]=1;
		}else{
			a[i].r=-1;
		}		
	}
	while(have[root]!=0) root++;
	dfs(root,1);
	if(maxn==n){
		cout<<"YES "<<ans;
	}else{
		cout<<"NO "<<root;
	}
	return 0;
}
