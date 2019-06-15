#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id,l,r,index,level;
}a[100];
vector<node> v1;
void dfs(int root,int index,int level){
	if(a[root].l!=-1) dfs(a[root].l,2*index+1,level+1);
	v1.push_back({root,0,0,index,level});
	if(a[root].r!=-1) dfs(a[root].r,2*index+1,level+1);	
}
bool cmp1(node a,node b){
	if(a.level==b.level) return a.index<b.index;
	return a.level<b.level;
}
int main(){
	int n;
	cin>>n;
	int have[100]={0},root=0;
	for(int i=0;i<n;i++){
		a[i].id=i;
		string l,r;
		cin>>l>>r;
		if(l!="-"){
			a[i].r=stoi(l);
			have[stoi(l)]=1;
		}else{
			a[i].r=-1;
		}
		if(r!="-"){
			a[i].l=stoi(r);
			have[stoi(r)]=1;
		}else{
			a[i].l=-1;
		}
	}
	while(have[root]==1) root++;
	dfs(root,0,0);
	vector<node> v2(v1);
	sort(v2.begin(),v2.end(),cmp1);
	for(int i=0;i<n;i++){
		if(i!=0) cout<<" ";
		cout<<v2[i].id;
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		if(i!=0) cout<<" ";
		cout<<v1[i].id;
	}
	return 0;
}
